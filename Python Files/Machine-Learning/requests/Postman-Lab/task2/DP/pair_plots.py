import matplotlib.pyplot as plot
import pandas as pd
import seaborn as sb

df = pd.read_csv("../processed.csv")
sb.pairplot(df, diag_kind="kde")
plot.savefig("./img/pair_plot.png")
