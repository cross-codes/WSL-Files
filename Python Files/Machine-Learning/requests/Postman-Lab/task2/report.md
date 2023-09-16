<div align="center">
<h1>ML Task - Round 2</h1>

The final report based on my attempt at this task. Also a documentation of my
thought process during the same.
</div>

Unmodified `.csv` file: `original.csv`

Processed `.csv` file: `processed.csv`

---

## (1) Exploratory Data Analysis

#### (1.1) Scouting

There are no descriptions for any of the columns, but here are my educated guesses:

(O) -> Potential outliers

(G) -> Using an educated guess

(U) -> Unknown meaning/interpretation

| Column Name        | Description                                                                                          |
|--------------------|------------------------------------------------------------------------------------------------------|
| sex                | Male -> (M) Female -> (F)                                                                            |
| age                | Measured in years                                                                                   |
| height             | Measured in cm                                                                                      |
| weight             | Measured in kg                                                                                      |
| waistline          | Most likely unit is cm                                                                              |
| sight_left (O)     | Unit unknown. - Most values in [0, 2]. - Outlier at 9.9                                             |
| sight_right (O)    | Unit unknown. - Most values in [0, 2]. - Outlier at 9.9                                             |
| hear_left (G)      | Unit unknown. - Most values in {1, 2}. - 1 likely corresponds to normal hearing, 2 to impaired hearing |
| hear_right (G)     | Unit unknown. - Most values in {1, 2}. - 1 likely corresponds to normal hearing, 2 to impaired hearing |
| SBP                | Systolic Blood Pressure, a measure of blood pressure when the heart beats. Units seem to be mm of mercury. |
| DBP                | Diastolic Blood Pressure, a measure of blood pressure when the heart is at rest. Units seem to be mm of mercury. |
| BLDS (U)           | I have no idea what this is.                                                                         |
| tot_chole          | Total cholesterol level in the blood. Units are likely mg/dl.                                         |
| HDL_chole          | High-Density Lipoprotein (HDL) cholesterol level in the blood. Units are likely mg/dl.               |
| LDL_chole          | Low-Density Lipoprotein (LDL) cholesterol level in the blood. Units are likely mg/dl.               |
| triglyceride       | Triglyceride level in the blood. Units are likely mg/dl.                                           |
| hemoglobin         | Hemoglobin level in the blood. Units are likely g/dl.                                               |
| urine_protein (G)  | Presence or quantity of protein in the urine. - Expressed in single-digit numbers. - Likely proportional to the amount of protein in the urine. |
| serum_creatinine   | Serum creatinine level in the blood, used to assess kidney function. Units are likely mg/dl.         |
| SGOT_AST           | Serum Glutamic Oxaloacetic Transaminase (SGOT/AST) level in the blood, related to liver function. Units are /l. |
| SGOT_ALT           | Serum Glutamic Pyruvic Transaminase (SGPT/ALT) level in the blood, related to liver function. Units are /l. |
| gamma_GTP          | Gamma-Glutamyl Transferase (GGT or gamma-GTP) level in the blood, related to liver and bile duct function. Units are /l. |
| SMK_stat_type_cd (U) | Smoking status or type of smoking. Values in {1, 2, 3}. Further analysis is required to determine what each number could represent. |
| DRK_YN             | Drinking status. Y (Yes), N (No).                                                                    |

#### (1.2) Data Cleansing process

##### (1.2.1) Removing null values and duplicates

File: `EDA/null_check.py`

```python
import pandas as pd

df = pd.read_csv("../original.csv")

missing_values = df.isnull().sum()

print("Columns with missing values: ")
for column, count in missing_values.items():
    if count > 0:
        print(f"{column}: {count} missing values")
```

No missing values were found

File: `EDA/duplicates.py`

```python
df = pd.read_csv("../original.csv")
print(df[df.duplicated].shape)  # (26, 24) -> 26 duplicates for 24 columns
print(df.describe())
df = df.drop_duplicates(keep="first")
df.to_csv("../processed.csv", index=False)
print(df.describe())
```

It is necessary to remove duplicate entries because we do not
want our models to over-fit. 26 entries is still negligible though.

##### (1.2.2) Addressing outliers

The best method according to most sources is using the interquartile range
approach to detect outliers.
First we start by generating the box plot for every column

File: `EDA/outliers.py`

Images: `EDA/img`

```python
def generate_box_plot(column_name):
    plt.figure(figsize=(10, 6))
    plt.boxplot(df[column_name], vert=False)
    plt.title("Box Plot for " + column_name)
    plt.xlabel(column_name)
    plt.savefig("./img/box_plot_" + column_name + ".png")
    return 0

for column in column_names:
    generate_box_plot(column)
```

where the column_names are defined as:

```python
column_names = [
    "age",
    "height",
    "weight",
    "waistline",
    "sight_left",
    "sight_right",
    "hear_left",
    "hear_right",
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
    "gamma_GTP",
]
```

Then we remove outliers for the following columns:

```python

columns_to_be_removed = [
    "sight_left",
    "sight_right",
    "waistline",
    "SBP",
    "DBP",
    "BLDS",
    "tot_chole",
    "triglyceride",
    "serum_creatinine",
    "SGOT_AST",
    "SGOT_ALT",
]
```

`gamma_GTP` was intentionally left out because I feel like I'd loose a lot of
data considering this box plot:

![gamma_GTP](./EDA/img/box_plot_gamma_GTP.png)

Honestly some of the parameters like `SGOT_AST` really seem important, as a
higher value indicates something related to
alcohol consumption, but I can't really tell how important each entry is,
without a domain expert.

I also have a suspicion that `sight_left` and `sight_right` must lie in (0, 1],
but I have no way to confirm this.

##### (1.2.3) Converting data types

`DRK_YN` contains entires in {"Y", "N"}, so I will convert them into {1, 0}.

I'll also use numbers for gender

File: `EDA/convert.py`

```python
df = pd.read_csv("../processed.csv")

df["DRK_YN"] = df["DRK_YN"].replace({"Y": 1, "N": 0})
df["sex"] = df["sex"].replace({"Male": 1, "Female": 2})
df.to_csv("../processed.csv", index=False)
```

##### (1.2.4) Feature engineering

This is just adding useful columns derived from other related columns
The height and weight are useful parameters for this test, but I think
it's better if we just combine them and use the BMI instead.

The formula for BMI is $\beta = \frac{\text{Mass(kg)}}{\text{Height(m)}^2}$
So I'm going to add this column next to the weight and height.

From the scouting, the height is in `cm`, so this needs to be accounted for.

File: `EDA\feature_engg.py`

```python
df = pd.read_csv("../processed.csv")
df["bmi"] = round(df["weight"] / ((df["height"] / 100) ** 2), 2)

columns_order = [
    "sex",
    "age",
    "height",
    "weight",
    "bmi",
    "waistline",
    "sight_left",
    "sight_right",
    "hear_left",
    "hear_right",
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
    "gamma_GTP",
    "SMK_stat_type_cd",
    "DRK_YN",
]

df = df[columns_order]
df.to_csv("../processed.csv", index=False)
```

The BMI (rounded off to two decimal) reports is now present next to the weight column

The columns seem to be meaningful in name, and there is only numerical input, so
this concludes my preliminary EDA. I may add more columns as I perform data
plotting however.

---

## (2) Data plotting

The objective is to check the relationship between various entries in the dataset.
To do this, I will try generating pair plots,
heatmaps and histograms between some relevant quantities

##### (2.1) Pair plots

A very memory intensive operation, needed a lot of time to perform

File: `DP/pair_plots.py`

Image: `DP/img/pair_plot.png`

![Pair Plot](./DP/img/pair_plot.png)

```python
import matplotlib.pyplot as plot
import pandas as pd
import seaborn as sb

df = pd.read_csv("../processed.csv")
sb.pairplot(df, diag_kind="kde")
plot.savefig("./img/pair_plot.png")
```

This is essentially a comparison of every column vs every other column.
The figure is very detailed, so you may zoom in to see each relationship

For example, the relationship between `age` and `DRK_YN` is demonstrated by the
first cell:

Relevant parameters seem to be `SGOT_AST` and `SGOT_ALT` for drinking.
Further research suggests that the `SGOT_AST`/`SGOT_ALT` ratio is [very
important for drinking detection](https://en.wikipedia.org/wiki/AST/ALT_ratio),
so I will add that column.

##### (2.2) Heatmaps

A heatmap is a tool to find the correlation strength among variables.
The higher the correlation, the darker the color

File: `DP/heatmaps.py`

Image: `DP/img/heatmap.py`

```python
df = pd.read_csv("../processed.csv")

columns_to_include = [
    "age",
    "height",
    "weight",
    "waistline",
    "sight_left",
    "sight_right",
    "hear_left",
    "hear_right",
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
    "gamma_GTP",
    "SMK_stat_type_cd",
    "DRK_YN",
]

df_subset = df[columns_to_include]

plot.figure(figsize=(12, 10))

heatmap = sns.heatmap(
    df_subset.corr(),
    annot=True,
    cmap="coolwarm",
    fmt=".2f",
    annot_kws={"size": 8},
)

heatmap.set_xticklabels(
    heatmap.get_xticklabels(),
    rotation=45,
    horizontalalignment="right",
)

heatmap.set_aspect("equal")
plot.savefig("./img/heatmap.png", bbox_inches="tight")
```

![Heatmap](./DP/img/heatmap.png)

From this heatmap, it becomes immediately clear that the
following parameters have a good correlation
with the drinking status of a person

(1) Height

(2) Weight

(3) Hemoglobin

(4) Serum Creatinine content

(5) Gamma-Glutamyl content

(6) Smoking status

#### (2.3) Histograms

I plotted some simple histograms based on the above parameters

File: `DP/histogram.py`

Images: `DP/img/*_histogram.py`

```python

df = pd.read_csv("../processed.csv")
plot.hist(df[df["column_1"] == 0]["column_2"], alpha=0.5, label="label1")
plot.hist(df[df["column_1"] == 1]["column_2"], alpha=0.5, label="label2")
plot.xlabel("column_2")
plot.ylabel("Frequency")
plot.legend()
```

![Histogram1](./DP/img/hemo_histogram.png)
![Histogram2](./DP/img/gamma_histogram.png)
![Histogram3](./DP/img/hemo_smoke_histogram.png)

All matching with the heatmap, which was by far the most useful

---

### (3) Model Making

Note: I'm on a terminal environment, so memory consumption is not something I'll
be including in this analysis. This is primarily because I do not have access
to the magic `%memit` command or an equivalent, and the standard ways of
measuring memory consumption would be dependent on my virtual environment's python
interpreter and the processes running on my laptop

#### (i) Linear Regression or Logistic Regression

File: `models/linear_regression.py`

```python
import time
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import accuracy_score, classification_report

start_time = time.time()

df = pd.read_csv("../processed.csv")
X = df.drop(columns=["DRK_YN", "sex"], axis=1)
y = df.DRK_YN

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=69
)

model = LinearRegression()
model.fit(X_train, y_train)

y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test, y_pred.round())
report = classification_report(y_test, y_pred.round())

print(f"Accuracy: {accuracy:.2f}")
print("Classification Report:")
print(report)

end_time = time.time()
elapsed_time = end_time - start_time

print(f"Time taken: {elapsed_time:.2f} seconds")
```

The result is as follows:

```bash
Accuracy: 0.72
Classification Report:
              precision    recall  f1-score   support

        -2.0       0.00      0.00      0.00         0
        -1.0       0.00      0.00      0.00         0
         0.0       0.71      0.74      0.73     98304
         1.0       0.73      0.69      0.71     97861
         2.0       0.00      0.00      0.00         0

    accuracy                           0.72    196165
   macro avg       0.29      0.29      0.29    196165
weighted avg       0.72      0.72      0.72    196165

Time taken: 1.87 seconds
```

However, I was able to optimise this by simply not including
columns with negative or zero correlation.
In particular, when

```python
columns=[
    "DRK_YN",
    "sex",
    "hear_left",
    "hear_right",
    "LDL_chole",
    "urine_protein",
]
```

The result is faster, but just as accurate

```bash
Accuracy: 0.72
Classification Report:
              precision    recall  f1-score   support

         0.0       0.71      0.74      0.73     98304
         1.0       0.73      0.69      0.71     97861
         2.0       0.00      0.00      0.00         0

    accuracy                           0.72    196165
   macro avg       0.48      0.48      0.48    196165
weighted avg       0.72      0.72      0.72    196165

Time taken: 1.72 seconds
```

##### (ii) Support Vector Machine

File: `models/svm.py`

```python

import time
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, classification_report

start_time = time.time()

df = pd.read_csv("../processed.csv")
X = df.drop(columns=["DRK_YN", "sex"], axis=1)
y = df.DRK_YN

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=69
)

svmc = SVC(kernel="rbf", C=1.0)
svmc.fit(X_train, y_train)


y_pred = svmc.predict(X_test)
accuracy = accuracy_score(y_test, y_pred.round())
report = classification_report(y_test, y_pred.round())

print(f"Accuracy: {accuracy:.2f}")
print("Classification Report:")
print(report)

end_time = time.time()
elapsed_time = end_time - start_time

print(f"Time taken: {elapsed_time:.2f} seconds")

```

I did not know the underlying distribution, so I choose a radial basis function
for my kernel.

Unfortunately, this does not seem to be working, because
even after 2 hours, the model was not finished.

Even if there were any potential gains in accuracy, the time
this model takes drags this down

##### (iii) Random Forest Classifiers

File: `models/random_forests.py`

```python
import time
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, classification_report

start_time = time.time()

df = pd.read_csv("../processed.csv")
X = df.drop(columns=["DRK_YN", "sex"], axis=1)
y = df.DRK_YN

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=69
)

model = RandomForestClassifier(n_estimators=100, random_state=69, n_jobs=-1)
model.fit(X_train, y_train)

y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test, y_pred)
report = classification_report(y_test, y_pred)

print(f"Accuracy: {accuracy:.2f}")
print("Classification Report:")
print(report)

end_time = time.time()
elapsed_time = end_time - start_time

print(f"Time taken: {elapsed_time:.2f} seconds")
```

The result is as follows:

```bash
Accuracy: 0.73
Classification Report:
              precision    recall  f1-score   support

           0       0.73      0.74      0.73     98304
           1       0.73      0.72      0.73     97861

    accuracy                           0.73    196165
   macro avg       0.73      0.73      0.73    196165
weighted avg       0.73      0.73      0.73    196165

Time taken: 84.89 seconds
```

It is only slightly more accurate than a linear regression
but the amount of time it takes is far more.
I also set `n_jobs=-1` to use all of my cores. Without this
the process took over 3 minutes

##### (iv) Neural Networks
