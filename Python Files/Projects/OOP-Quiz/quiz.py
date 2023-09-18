# quiz.py

from time import sleep
from quiz_control import Quiz_Control as quiz_init
from test_questions import question_data

if __name__ == "__main__":
    quiz = quiz_init(2, -1)

    print("Initializing questions...")
    for models in question_data:
        question = models["text"]
        answer = models["answer"]
        quiz.add_model(question, answer)
    sleep(0.5)

    print("Starting quiz...\n")
    sleep(0.5)
    print("----------------------------------------")

    while True:
        status, question = quiz.ask_question()
        if status == -1:
            quiz.get_stats()
            break
        answer = quiz.get_answer(question)
        response = quiz.get_response()
        status = quiz.evaluate_response(question, answer, response)
        if status == -1:
            print("Error encountered, quitting")
            break
