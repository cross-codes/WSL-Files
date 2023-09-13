import pandas as pd
import matplotlib.pyplot as plot

df = pd.read_csv("../processed.csv")

plot.scatter(df["hemoglobin"], df["DRK_YN"])
plot.xlabel("Hemoglobin")
plot.ylabel("DRK_YN")
plot.title("Scatter Plot of Hemoglobin vs. DRK_YN")

plot.savefig("./img/hemo_vs_drinking.png")
