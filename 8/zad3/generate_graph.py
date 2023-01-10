import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("./zad3v2.csv")
print(df.columns)
plt.figure(figsize=(8,5))
# plt.title("Country data")
a = [i for i in range(df["Real"].count())]
plt.plot(a, df["Real"], "b-", label="Real")
plt.plot(a, df["Imag"], "g-", label="Imag")
# plt.plot(df3.columns, df3.loc["Austria"], ".-", color="purple", label="Austria")
# plt.plot(df3.columns, df3.loc["France"], ".", linestyle='dashdot', color="#ff9900", label="France")
# plt.xticks(df3.columns[::2])
# plt.xlabel("Date")
# plt.ylabel("Value")
plt.legend(loc="upper right")
plt.savefig('./graph.png')
plt.show()
# print(df)