# 紫色五角星，角上带蓝色圆圈，无填充颜色

from turtle import*

pensize(5)

for i in range(5):
    color("purple")
    forward(100)
    left(36)

    #画出蓝色圆形
    color("blue")
    circle(15)

    # 调整角度，继续画五角星
    right(180)