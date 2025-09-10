import time
from db import patients_db  # pyright: ignore[reportImplicitRelativeImport]
from query_list import queries  # pyright: ignore[reportImplicitRelativeImport]
from query_agent import (  # pyright: ignore[reportImplicitRelativeImport]
    SelectiveQueryAgent,
)
from guardrail import GuardRail  # pyright: ignore[reportImplicitRelativeImport]

agent: SelectiveQueryAgent = SelectiveQueryAgent(patients_db)
guard: GuardRail = GuardRail()

for index, query in enumerate(queries):
    time.sleep(2)
    print(f"Query #{index}:")
    res: str | None = agent.query(query)
    print("Agent response: ", res)
    if res is not None:
        print(guard.cleanse(query, res))
    else:
        print("Error displaying response")
    print("-----------------")
