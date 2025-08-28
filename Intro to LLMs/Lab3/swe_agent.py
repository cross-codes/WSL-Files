import subprocess
from google import genai
from google.genai import types

client = genai.Client()

def cleanse_output(output):
    output = output.strip();
    if output.startswith("```"):
        output = output.removeprefix("```python")

    if output.endswith("```"):
        output = output.removesuffix("```")

    output = output.lstrip().rstrip()

    return output


MAX_ITERATIONS: int = 5
task = "Write a python program that reads user input (n) and returns the first n catalan numbers"

augmented_prompt = f'''
Only provide functional and complete code for the following task: {task}.
Do not wrap the code in markdown fences like ```python.
What you provide will be fed into a file for execution without changes.
'''

print("Generating code (first iteration)")

code = client.models.generate_content(
    model = "gemini-2.5-flash",
    contents = augmented_prompt,
    config = types.GenerateContentConfig(
        thinking_config=types.ThinkingConfig(thinking_budget=10)
    ),
)

print ("First code version generated")

cleaned_code = cleanse_output(code.text)

with open("prompt_output.py", "w") as fh:
    fh.write(cleaned_code)

fh.close()

print()

test_prompt = f'''
The following code is stored in a file called "prompt_output.py"
Code: {cleaned_code}

It is an attempt to solve the following task (you do not have to solve it again:)
Task: {task}

Write a python script that imports the file with that function (assume it is in the same directory).
The script should run a very comprehensive number of tests to verify if the output of each test is correct
The script should not print anything for every test that passes, and 'test failed' for every test that failed.
For every test that failed, the script should display the test case that caused the code to fail
Do not print anything else except the script.
'''

code = client.models.generate_content(
    model = "gemini-2.5-flash",
    contents = test_prompt,
    config = types.GenerateContentConfig(
        thinking_config=types.ThinkingConfig(thinking_budget=10)
    ),
)

print("Generating test suite (first iteration)")

test_code = cleanse_output(code.text)

with open("prompt_test.py", "w") as fh:
    fh.write(test_code)

fh.close()

for i in range(MAX_ITERATIONS):
    print(f"\n--- Iteration {i + 1}/{MAX_ITERATIONS} ---")
    print("Executing test suite 'prompt_test.py'...")

    process = subprocess.run(
        ['python', 'prompt_test.py'],
        capture_output=True,
        text=True
    )

    test_output = (process.stdout + process.stderr).strip()

    if not test_output:
        print("\nAC. The generated code is correct.")
        success = True
        break
    else:
        print("Tests failed. Attempting to fix the code...\n")

        if i == MAX_ITERATIONS - 1:
            print("Failed to fix within the given iterations")
            break

        fix_prompt = f'''
        The following python code is an attempt to solve the task: "{task}"
        Current Code:
        ---
        {cleaned_code}
        ---
        However, it failed the tests with this error output:
        ---
        {test_output}
        ---

        Please fix the original code so that it passes the tests.
        Only provide the complete, corrected, and functional python code for the task.
        Do not explain the changes or add any extra text.
        Do not wrap the code in markdown fences like ```python.
        '''
        print("Regenerating code based on test failures...")

        response = client.models.generate_content(
            model = "gemini-2.5-flash",
            contents = fix_prompt,
            config = types.GenerateContentConfig(
            thinking_config=types.ThinkingConfig(thinking_budget=10)
            ),
        )

        cleaned_code = cleanse_output(response.text)

        with open("prompt_output.py", "w") as fh:
            fh.write(cleaned_code)

        print("Retry attempt")
