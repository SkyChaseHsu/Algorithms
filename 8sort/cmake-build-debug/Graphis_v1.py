import csv
import matplotlib.pyplot as plt

filename = 'expriData.csv'

data_names = []
color = ['#009999', '#FFAA00', '#1240AB', '#FF7400']

with open(filename, 'r') as f:
	reader = csv.reader(f)
	header_row = next(reader)
	for index, values in enumerate(reader):
		if values[0] not in data_names:
			data_names.append(values[0])
			exec('{}_x_values = []'.format(values[0]))
			exec('{}_y_values = []'.format(values[0]))
			exec('{}_x_values.append({})'.format(values[0], values[1]))
			exec('{}_y_values.append({})'.format(values[0], values[2]))

		else:
			exec('{}_x_values.append({})'.format(values[0], values[1]))
			exec('{}_y_values.append({})'.format(values[0], values[2]))

color_flag = 0;		

for sort_name in data_names:

	exec('plt.plot({}_x_values, {}_y_values, linewidth = 2, label = "{}", color = "{}", linestyle = "-")'.
	format(sort_name, sort_name, sort_name, color[color_flag]))\

	exec('plt.scatter({}_x_values, {}_y_values, 50, color ="{}")'.format(sort_name, sort_name, color[color_flag]))
	color_flag += 1

plt.title("Relation of Time and N", fontsize = 24, fontweight = 'bold')
plt.xlabel("N", fontsize = 12)
plt.ylabel("Time(ms)", fontsize = 12)

plt.grid(axis="x")
plt.grid(axis="y")

plt.legend(loc = 'upper left', fontsize = 10)

plt.show()