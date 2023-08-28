from __future__ import absolute_import, division, print_function, unicode_literals

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from IPython.display import clear_output
import tensorflow as tf

print("---------------------------------------------------------")

# Load dataset.
dftrain = pd.read_csv(
    "https://storage.googleapis.com/tf-datasets/titanic/train.csv"
)  # Training dataset
dfeval = pd.read_csv(
    "https://storage.googleapis.com/tf-datasets/titanic/eval.csv"
)  # Testing dataset
y_train = dftrain.pop("survived")  # Pop the "survived" row from the training data
y_eval = dfeval.pop("survived")  # Pop the "survived" row from the testing data

dftrain.age.hist(bins=20)
plt.xlabel("Age")
plt.ylabel("Frequency")
plt.title("Histogram of ages")
plt.savefig("histogram.png")
plt.clf()

dftrain.sex.value_counts().plot(kind="barh")
plt.xlabel("Count")
plt.ylabel("Gender")
plt.title("Bar graph of gender")
plt.savefig("bar_graph1.png")
plt.clf()

dftrain["class"].value_counts().plot(kind="barh")
plt.xlabel("Count")
plt.ylabel("Class")
plt.title("Bar graph of class")
plt.savefig("bar_graph2.png")
plt.clf()

pd.concat([dftrain, y_train], axis=1).groupby("sex").survived.mean().plot(
    kind="barh"
).set_xlabel("% survive")
plt.xlabel("Percentage survival")
plt.ylabel("Gender")
plt.title("Bar graph of survival percentage")
plt.savefig("bar_graph3.png")
plt.clf()

"""
print(dftrain.head())     -> Prints the head of the table dftrain
print(dftrain.loc[0])     -> Prints the first row's data
print(dftrain["age"])     -> Prints all rows with "age" as the column
print(dftrain.describe()) -> Print some useful characteristics of the dataset
print(dftrain.shape)      -> Print the shape of the dataset
"""
