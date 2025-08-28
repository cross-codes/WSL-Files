import os
from langchain_community.utilities import DuckDuckGoSearchAPIWrapper
from langchain_core.output_parsers import StrOutputParser
from langchain_core.prompts import ChatPromptTemplate
from langchain_core.runnables import RunnablePassthrough
from langchain_google_genai import ChatGoogleGenerativeAI
from langchain import hub

template = """Answer the users question based only on the following context:

<context>
{context}
</context>

Question: {question}
"""
prompt = ChatPromptTemplate.from_template(template)
model = ChatGoogleGenerativeAI(
    model="models/gemini-2.5-flash",
    google_api_key=os.environ.get("GEMINI_API_KEY")
)
search = DuckDuckGoSearchAPIWrapper()

def retriever(query):
    return search.run(query)

chain = (
    {"context": retriever, "question": RunnablePassthrough()}
    | prompt
    | model
    | StrOutputParser()
)

simple_query = "what is langchain?"
print(chain.invoke(simple_query))

print("\nDistracted query:\n")

distracted_query = "man that sam bankman fried trial was crazy! what is langchain?"
print(chain.invoke(distracted_query))

print("\nWith retreiver\n")

template = """
Provide a better search query for \
web search engine to answer the given question, end \
the queries with ’**’. Question: \
{x} Answer:
"""

rewrite_prompt = ChatPromptTemplate.from_template(template)
rewrite_prompt = hub.pull("langchain-ai/rewrite")
print(rewrite_prompt.template)

def _parse(text):
    return text.strip('"').strip("**")

rewriter = rewrite_prompt | model | StrOutputParser() | _parse
rewriter.invoke({"x": distracted_query})
rewrite_retrieve_read_chain = (
    {
        "context": {"x": RunnablePassthrough()} | rewriter | retriever,
        "question": RunnablePassthrough(),
    }
    | prompt
    | model
    | StrOutputParser()
)
print(rewrite_retrieve_read_chain.invoke(distracted_query))
