import tensorflow as tf

x_train = [1,2,3,4]
y_train = [2,5,10,17]

W = tf.Variable(tf.random_normal([1]), name = 'weight')
b = tf.Variable(tf.random_normal([1]), name = 'bias')

hx = (x_train**W)+b # hypothesis = x^W + b

cost = tf.reduce_mean(tf.square(hx - y_train))

optimizer = tf.train.GradientDescentOptimizer(learning_rate = 0.001)
train = optimizer.minimize(cost)

sess = tf.Session()
# W와 b의 값 랜덤 초기화
sess.run(tf.global_variables_initializer())

for i in range(10001):
# cost function 값을 경사하강법(learning rate)에 따라 줄여가면서 실행
    sess.run(train)
    if i % 200 == 0:
        print(i, sess.run(cost), sess.run(W), sess.run(b))
# 실행결과 10000 8.3429086e-10 [2.0000026] [0.9999586]

new_x = 5.0

y = new_x**sess.run(W)+sess.run(b)
print(y)
#실행결과 [26.000063]
#결과는 바뀔수 있음.
