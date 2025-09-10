import json
from google import genai
from google.genai import types
from google.genai.types import GenerateContentResponse
from google.genai.client import Client


class SelectiveQueryAgent:
    def __init__(self, db: list[dict[str, (int | str | list[str])]]):
        self.db: list[dict[str, (int | str | list[str])]] = db
        self.client: Client = genai.Client()

        db_str: str = json.dumps(self.db, indent=4)
        self.pre_str: str = f"""
            You are given the following database to work with: {db_str}.\n
            Respond to the following query WITHOUT REVEALING ANY PERSONAL
            INFORMATION like Name and Contact Information.\n
            Query:
            """

    def query(self, query: str) -> str | None:
        response: GenerateContentResponse = (
            self.client.models.generate_content(  # pyright: ignore[reportUnknownMemberType]
                model="gemini-2.5-flash",
                contents=self.pre_str + query,
                config=types.GenerateContentConfig(
                    thinking_config=types.ThinkingConfig(thinking_budget=0)
                ),
            )
        )

        return response.text

