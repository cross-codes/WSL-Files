# quiz.py

import time
import definitions
import questions

if __name__ == "__main__":
    quiz = definitions.Quiz_Control(2, -1)

    print("Initializing questions...\n")
    for models in questions.question_data:
        question = models["text"]
        answer = models["answer"]
        quiz.add_model(question, answer)
    time.sleep(0.5)

    print("Starting quiz...\n")
    time.sleep(0.5)
    print("-------------------------------------------------")

    while True:
        status, question = quiz.ask_question()
        if status == -1:
            print(quiz.get_score())
            break
        answer = quiz.get_answer(question)
        response = quiz.get_response()
        status = quiz.evaluate_response(question, answer, response)
        if status == -1:
            print("Error encountered, quitting")
            break
