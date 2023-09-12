import pandas as pd

df = pd.read_csv("../processed.csv")

df["DRK_YN"] = df["DRK_YN"].replace({"Y": 1, "N": 0})
df.to_csv("../processed.csv", index=False)
