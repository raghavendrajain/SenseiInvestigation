import numpy as np
import matplotlib.pyplot as plt
fig = plt.figure()
ax1 = fig.add_subplot(111)

ax1.set_title("The velocity of target object")    
ax1.set_xlabel('x component of velocity')
ax1.set_ylabel('y component of velocity')

data = np.genfromtxt('example.csv', delimiter=',', skip_header=3,names=['x', 'y'])

colormap = np.array(['r', 'g'])
ax1.plot(data['x'], data['y'], color='g', label='the data')
# leg = ax1.legend()

plt.show()

        	

