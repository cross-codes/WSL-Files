from google import genai
from google.genai import types

client = genai.Client()

prompt = """
For a SDE internship at a IMC, would you recommend I master C++ (have working proficiency), or I start learning Rust (out of interest))
"""

response = client.models.generate_content(
    model="gemini-2.5-flash",
    contents=prompt,
    config = types.GenerateContentConfig(thinking_config=types.ThinkingConfig(thinking_budget=2000))
)
print(response.text)
