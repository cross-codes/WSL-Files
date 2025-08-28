import os
from langchain_core.output_parsers import StrOutputParser
from langchain_core.prompts import ChatPromptTemplate, FewShotChatMessagePromptTemplate
from langchain_core.runnables import RunnableLambda
from langchain_google_genai import ChatGoogleGenerativeAI
from langchain_community.utilities import DuckDuckGoSearchAPIWrapper
from langchain import hub


examples = [
    {
        "input": "Could the members of The Police perform lawful arrests?",
        "output": "what can the members of The Police do?",
    },
    {
        "input": "Jan Sindel’s was born in what country?",
        "output": "what is Jan Sindel’s personal history?",
    },
]

example_prompt = ChatPromptTemplate.from_messages(
    [
        ("human", "{input}"),
        ("ai", "{output}"),
    ]
)

few_shot_prompt = FewShotChatMessagePromptTemplate(
    example_prompt=example_prompt,
    examples=examples,
)

prompt = ChatPromptTemplate.from_messages(
    [
        (
            "system",
            """You are an expert at world knowledge. Your task is to step back and paraphrase a question to a more generic step-back question, which is easier to answer. Here are a few examples:""",
        ),
        few_shot_prompt,
        ("user", "{question}"),
    ]
)

model = ChatGoogleGenerativeAI(
    model="models/gemini-2.5-flash",
    google_api_key=os.environ.get("GEMINI_API_KEY")
)

question_gen = prompt | model | StrOutputParser()
question = "was chatgpt around while trump was president?"
print("Step back question:")
print(question_gen.invoke({"question": question}))

search = DuckDuckGoSearchAPIWrapper(max_results=4)

def retriever(query):
    return search.run(query)

print("\nRetreived results (raw): ")
print(retriever(question))
print(retriever(question_gen.invoke({"question": question})))

response_prompt = hub.pull("langchain-ai/stepback-answer")
chain = (
    {
        "normal_context": RunnableLambda(lambda x: x["question"]) | retriever,
        "step_back_context": question_gen | retriever,
        "question": lambda x: x["question"],
    }
    | response_prompt
    | model
    | StrOutputParser()
)

print(chain.invoke({"question": question}))
