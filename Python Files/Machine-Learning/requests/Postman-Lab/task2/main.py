import pandas as pd

df = pd.read_csv("./smoking_driking_dataset_Ver01.csv")

missing_values = df.isnull().sum()

print("Columns with missing values: ")
for column, count in missing_values.items():
    if count > 0:
        print(f"{column}: {count} missing values")
