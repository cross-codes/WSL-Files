# definitions.py

import time
from prettytable import PrettyTable


class Model:
    def __init__(self, text, answer):
        self.question = text
        self.answer = answer


class Quiz_Control:
    def __init__(self, positive_marks, negative_marks):
        self.questions = {}
        self.score = 0
        self.streak = 0
        self.plus = positive_marks
        self.minus = negative_marks
        self.unasked_questions = set()
        self.asked_questions = set()
        self.correct_questions = 0
        self.incorrect_questions = 0

    def add_model(self, question, answer):
        self.questions[(question, answer)] = Model(question, answer)
        self.unasked_questions.add((question, answer))
        return 0

    def remove_model(self, question, answer):
        if (question, answer) in self.questions:
            del self.questions[(question, answer)]
            self.unasked_questions.discard((question, answer))
            self.asked_questions.discard((question, answer))
        return 0

    def mod_score(self, status):
        if status is False:
            self.score += self.minus
            self.incorrect_questions += 1
            self.streak = 0
            print("Incorrect answer.")
            print("Current Streak: ", self.streak)
            return 0
        self.score += self.plus
        self.correct_questions += 1
        self.streak += 1
        print("Correct answer")
        print("Current Streak: ", self.streak)
        return self.score

    def evaluate_response(self, question, answer, response):
        model = self.questions.get((question, answer))
        if model is None:
            return -1
        self.mod_score(model.answer == response)
        return 0

    def ask_question(self):
        if self.unasked_questions:
            model_tuple = self.unasked_questions.pop()
            self.asked_questions.add(model_tuple)
            model = self.questions.get(model_tuple)
            print("Q" + str(len(self.asked_questions)) + ": " + model.question)
            return 0, model.question

        return -1, None

    def get_answer(self, question):
        for _, model in self.questions.items():
            if model.question == question:
                return model.answer
        return -1

    def get_response(self):
        true_literals = {
            "T",
            "t",
            "TRUE",
            "True",
            "true",
            "yes",
            "Yes",
            "y",
            "Y",
            "YES",
        }
        false_literals = {
            "F",
            "f",
            "False",
            "false",
            "FALSE",
            "no",
            "No",
            "n",
            "N",
            "NO",
        }
        while True:
            res = str(input("Enter your answer: "))
            if res in true_literals:
                return "True"
            if res in false_literals:
                return "False"

            print("Invalid input, try again \n")

    def get_score(self):
        print("Compiling total score...\n")
        accuracy = round(
            (
                self.correct_questions
                / (self.correct_questions + self.incorrect_questions)
            )
            * 100,
            2,
        )
        time.sleep(0.5)
        display_table = PrettyTable(
            ["Correct questions", "Incorrect questions", "Accuracy", "Total score"]
        )
        display_table.add_row(
            [self.correct_questions, self.incorrect_questions, accuracy, self.score]
        )
        print(display_table)
