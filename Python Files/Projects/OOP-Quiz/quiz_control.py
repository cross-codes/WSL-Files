# quiz_control.py

from __future__ import annotations
import time
from prettytable import PrettyTable


class Model:
    def __init__(self, text: str, answer: str):
        self.question: str = text
        self.answer: str = answer


class Quiz_Control:
    TRUTH_LITERALS = {
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

    FALSE_LITERALS = {
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

    def __init__(self, positive_marks: int, negative_marks: int):
        self.questions: dict = {}
        self.score: int = 0
        self.stats: dict = {
            "curr_streak": 0,
            "streak_arr": [],
            "correct_questions": 0,
            "incorrect_questions": 0,
            "time_intervals": [],
        }
        self.plus: int = positive_marks
        self.minus: int = negative_marks
        self.unasked_questions: set = set()
        self.asked_questions: set = set()
        self.timing: dict = {"time_start": 0.0, "time_end": 0.0}

    def add_model(self, question: str, answer: str) -> int:
        self.questions[(question, answer)] = Model(question, answer)
        self.unasked_questions.add((question, answer))
        return 0

    def remove_model(self, question: str, answer: str) -> int:
        if (question, answer) in self.questions:
            del self.questions[(question, answer)]
            self.unasked_questions.discard((question, answer))
            self.asked_questions.discard((question, answer))
        return 0

    def mod_score(self, status: bool) -> int:
        if status is False:
            self.score += self.minus
            self.mod_streak(status)
            self.stats["incorrect_questions"] += 1
            return 0
        self.score += self.plus
        self.stats["correct_questions"] += 1
        self.mod_streak(status)
        return self.score

    def mod_streak(self, status: bool) -> int:
        if status is False:
            self.stats["streak_arr"].append(self.stats["curr_streak"])
            self.stats["curr_streak"] = 0
            print("Incorrect answer.")
            print("Current Streak: ", self.stats["curr_streak"])
            return 0
        self.stats["curr_streak"] += 1
        print("Correct answer")
        print("Current Streak: ", self.stats["curr_streak"])
        return 0

    def evaluate_response(self, question: str, answer: str, response: str) -> int:
        model = self.questions.get((question, answer))
        if model is None:
            return -1
        self.mod_score(model.answer == response)
        return 0

    def ask_question(self) -> tuple:
        if self.unasked_questions:
            model_tuple = self.unasked_questions.pop()
            self.asked_questions.add(model_tuple)
            model = self.questions.get(model_tuple)
            print("Q" + str(len(self.asked_questions)) + ": " + model.question)
            return 0, model.question

        return -1, None

    def get_answer(self, question: str) -> str | int:
        for _, model in self.questions.items():
            if model.question == question:
                return model.answer
        return -1

    def assert_time(self, state="start") -> int:
        if state == "start":
            self.timing["time_start"] = time.time()
            return 0
        self.timing["time_end"] = time.time()
        self.stats["time_intervals"].append(
            self.timing["time_end"] - self.timing["time_start"]
        )
        return 0

    def get_response(self) -> str:
        while True:
            self.assert_time()
            res = str(input("Enter your answer: "))
            if res in self.TRUTH_LITERALS:
                self.assert_time("end")
                return "True"
            if res in self.FALSE_LITERALS:
                self.assert_time("end")
                return "False"

            print("Invalid input, try again \n")

    def get_score(self) -> None:
        self.stats["streak_arr"].append(self.stats["curr_streak"])
        print("Compiling total score...\n")
        accuracy = round(
            (
                self.stats["correct_questions"]
                / (self.stats["correct_questions"] + self.stats["incorrect_questions"])
            )
            * 100,
            2,
        )
        highest_streak = max(self.stats["streak_arr"])
        average_time = round(
            sum(self.stats["time_intervals"]) / len(self.stats["time_intervals"]), 2
        )
        time.sleep(0.5)
        display_table = PrettyTable(
            [
                "Correct questions",
                "Incorrect questions",
                "Highest Streak",
                "Accuracy",
                "Average Time",
                "Total score",
            ]
        )
        display_table.add_row(
            [
                self.stats["correct_questions"],
                self.stats["incorrect_questions"],
                highest_streak,
                accuracy,
                str(average_time) + " s",
                self.score,
            ]
        )
        print(display_table)
