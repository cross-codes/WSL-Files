# definitions.py


class Model:
    def __init__(self, text, answer):
        self.question = text
        self.answer = answer


class Quiz_Control:
    def __init__(self, positive_marks, negative_marks):
        self.questions = {}
        self.score = 0
        self.plus = positive_marks
        self.minus = negative_marks
        self.unasked_questions = set()
        self.asked_questions = set()

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
            return 0
        self.score += self.plus
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
        res = str(input("Enter your answer: "))
        return res

    def get_score(self):
        return self.score
