import os
from langchain_google_genai import ChatGoogleGenerativeAI
from langchain.prompts import PromptTemplate
from langchain.chains import LLMChain
from typing import List

def create_subquery_decomposition_template() -> PromptTemplate:
    template = """
    You are an AI assistant tasked with breaking down complex queries into simpler sub-queries for a RAG system.
    Given the original query, decompose it into 2-4 simpler sub-queries that, when answered together, would provide a comprehensive response to the original query.

    Original query: {original_query}

    example: What are the impacts of climate change on the environment?

    Sub-queries:
    1. What are the impacts of climate change on biodiversity?
    2. How does climate change affect the oceans?
    3. What are the effects of climate change on agriculture?
    4. What are the impacts of climate change on human health?
    """
    return PromptTemplate(input_variables=["original_query"], template=template)

def build_subquery_decomposer_chain(llm: ChatGoogleGenerativeAI) -> LLMChain:
    prompt_template = create_subquery_decomposition_template()
    return prompt_template | llm

def decompose_query(original_query: str, subquery_chain: LLMChain) -> List[str]:
    response = subquery_chain.invoke(original_query).content
    sub_queries = [q.strip() for q in response.split('\n') if q.strip() and not q.strip().startswith('Sub-queries:')]
    return sub_queries

if __name__ == "__main__":
    llm = ChatGoogleGenerativeAI(
        model="models/gemini-2.5-flash",
        google_api_key=os.environ.get("GEMINI_API_KEY")
    )

    subquery_chain = build_subquery_decomposer_chain(llm)
    original_query = "Is IMC trading a market maker?"
    sub_queries = decompose_query(original_query, subquery_chain)
    print("\nSub-queries:")
    for i, sub_query in enumerate(sub_queries, 1):
        print(f"{i}. {sub_query}")
