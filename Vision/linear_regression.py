#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Dec 12 13:48:40 2018

@author: bskim
"""

#Tensorflow 는 구글에서 만든 opensource library
#Data flow를 통한 numerical computation
#1.빌드 2.session 실행 3.update and return values
# 노드를 placeholder로 만들어줌 자유로운 변수 feed dict를 이용하여 변수넘김
#Rank : 몇차원 배열인지 
#shape : [n, m](2차원일 경우)
#type : 형 Data의 모양
#loss(cost) function : (H(x) - y)^2 기본적인 컨셉
# 제곱의 의미 : 항상 양수 & 오류가 클수록 기하급수적으로 커짐.
#학습과정에서 손실함수의 최소화과정이 목표이다.

import tensorflow as tf

x_train = [1,2,3]
y_train = [1,2,3]

W = tf.Variable(tf.random_normal([1]), name = 'weight')
b = tf.Variable(tf.random_normal([1]), name = 'bias')

hx = x_train*W +b

cost = tf.reduce_mean(tf.square(hx - y_train))

optimizer = tf.train.GradientDescentOptimizer(learning_rate = 0.01)
train = optimizer.minimize(cost)

sess = tf.Session()
# W와 b의 값 랜덤 초기화
sess.run(tf.global_variables_initializer())

for i in range(2001):
# cost function 값을 경사하강법(learning rate)에 따라 줄여가면서 실행
    sess.run(train)
    if i % 20 == 0:
        print(i, sess.run(cost), sess.run(W), sess.run(b))
# 실결과 2000 2.4564352e-07 [0.9994243] [0.00130855]
