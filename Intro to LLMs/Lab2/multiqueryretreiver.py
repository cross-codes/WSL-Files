import os, logging
from langchain_chroma import Chroma
from langchain_community.document_loaders import WebBaseLoader
from langchain_google_genai import GoogleGenerativeAIEmbeddings
from langchain_text_splitters import RecursiveCharacterTextSplitter
from langchain.retrievers.multi_query import MultiQueryRetriever
from langchain_google_genai import ChatGoogleGenerativeAI

loader = WebBaseLoader("https://lilianweng.github.io/posts/2023-06-23-agent/")
data = loader.load()

text_splitter = RecursiveCharacterTextSplitter(chunk_size=500, chunk_overlap=0)
splits = text_splitter.split_documents(data)

embedding = GoogleGenerativeAIEmbeddings(
    model="models/embedding-001",
    google_api_key=os.environ.get("GEMINI_API_KEY")
)
vectordb = Chroma.from_documents(documents=splits, embedding=embedding)

question = "What are the approaches to Task Decomposition"
llm = ChatGoogleGenerativeAI(
    model="models/gemini-2.5-flash",
    google_api_key=os.environ.get("GEMINI_API_KEY")
)
retriever_from_llm = MultiQueryRetriever.from_llm(
    retriever=vectordb.as_retriever(), llm=llm
)

logging.basicConfig()
logging.getLogger("langchain.retrievers.multi_query").setLevel(logging.INFO)

unique_docs = retriever_from_llm.invoke(question)
print(len(unique_docs))
