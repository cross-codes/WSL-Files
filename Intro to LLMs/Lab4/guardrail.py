from google import genai
from google.genai import types
from google.genai.types import GenerateContentResponse
from google.genai.client import Client


class GuardRail:
    def __init__(self):
        self.client: Client = genai.Client()

        self.pre_str: str = f"""
            A sister agent has responded to a user query, based on a healthcare database.

            If the response has personal information like contact details,
            that was not provided by the user, omit those details and rewrite the response.

            Only return the rewritten response.
            If no changes are needed:
            Return the response as is, without any additional text
            Else 
            (1) Print in all caps: REDACTED SENSITIVE INFORMATION
            (2) Add line breaks like -----
            (3) Rewrite the prompt after, with no additional changes

            User query:
            """

    def cleanse(self, query: str, res: str) -> str | None:
        response: GenerateContentResponse = (
            self.client.models.generate_content(  # pyright: ignore[reportUnknownMemberType]
                model="gemini-2.5-flash",
                contents=self.pre_str + query + f"\nAgent Response: {res}",
                config=types.GenerateContentConfig(
                    thinking_config=types.ThinkingConfig(thinking_budget=50)
                ),
            )
        )

        return response.text
