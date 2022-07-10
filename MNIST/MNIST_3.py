import matplotlib.pyplot as plt
import keras
from keras.datasets import mnist
from keras.utils import np_utils
from keras.models import Sequential
from keras.layers.core import Dense
from sklearn.neural_network import MLPClassifier
from keras.callbacks import Callback

(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_train = x_train.reshape(len(x_train), -1)  # 二维变一维
x_test = x_test.reshape(len(x_test), -1)
x_train = x_train.astype('float32') 
x_test = x_test.astype('float32')
x_train = (x_train ) / 255
x_test = (x_test ) / 255
y_train = np_utils.to_categorical(y_train, num_classes=10)  #one-hot。若原來為5則轉換後為[0. 0. 0. 0. 0. 1. 0. 0. 0. 0.]
y_test = np_utils.to_categorical(y_test, num_classes=10)
loss= []

class PrintStatsCallback(keras.callbacks.Callback):
    def on_batch_end(self, epoch, logs=None):
        loss.append(logs.get('loss'))

#定義model
model = Sequential()
model.add(Dense(300, input_shape=(784,), activation='relu'))  #hidden layer
model.add(Dense(10, activation='sigmoid'))  # output layer
model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])
model.fit(x_train, y_train, epochs=1, batch_size=20, verbose=1, validation_split=0.05,callbacks=[PrintStatsCallback()])
#loss = history.history['loss']
plt.plot(loss)

