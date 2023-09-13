import pandas as pd
import seaborn as sb
import matplotlib.pyplot as plot

df = pd.read_csv("../processed.csv")
df = df[
    [
        "SBP",
        "DBP",
        "BLDS",
        "tot_chole",
        "HDL_chole",
        "LDL_chole",
        "triglyceride",
        "hemoglobin",
        "urine_protein",
        "serum_creatinine",
        "SGOT_AST",
        "SGOT_ALT",
        "AST/ALT",
        "gamma_GTP",
        "SMK_stat_type_cd",
        "DRK_YN",
    ]
]

plot.figure(figsize=(10, 8))

heatmap = sb.heatmap(
    df.corr(), annot=True, cmap="coolwarm", fmt=".2f", annot_kws={"size": 10}
)
heatmap.set_xticklabels(
    heatmap.get_xticklabels(), rotation=45, horizontalalignment="right"
)
heatmap.set_aspect("equal")
plot.savefig("./img/heatmap.png")
