import random
import numpy as np
import matplotlib.pyplot as plt
from keras.datasets import mnist
from keras.models import load_model

# 加載 
mymodel = load_model('model.h5')
(x_train,y_train), (x_test, y_test) = mnist.load_data()  # 划分MNIST训练集、测试集

# 隨機
index = random.randint(0, x_test.shape[0])
x = x_test[index]
y = y_test[index]

plt.figure()
plt.subplot(121)
plt.imshow(x, cmap='gray_r')
plt.title("LABEL : {}".format(y))

# 預測
x.shape = (1, 784)  # 轉成1*784
predict = mymodel.predict(x)
predict = np.argmax(predict)  #取最大值的位置
print('ANSWER : ', y)
print('PREDICT : ', predict)

ans = np.zeros(10)
x_axis = ['0','1','2','3','4','5','6','7','8','9']

for i in range(10):
    if( i == predict):
        ans[i] = 1

plt.subplot(122)
plt.bar(x_axis,ans)
plt.title('predict answer')

