"""
鼓励师
"""
import random

# 播放声音 : playsound
# 监听键盘按键: 连续按键n次,播放一次音频

from pynput import keyboard
from playsound import playsound
from threading import Thread

count = 0
soundList = ['sound/1.mp3', 'sound/2.mp3', 'sound/3.mp3']
def onRelease(key):
    """
    这个函数是用户释放键盘是被表调用, 这是回调函数
    :param key:  按下的哪一个键
    :return:
    """
    print(key)
    global count
    count += 1
    if count % 10 == 0:
        # 播放音频
        i = random.randint(0, len(soundList)-1)
        # 此处的播放音频,这里要耗费时间,可以使用线程来播放音频,这里暂时不涉及
        # playsound(soundList[i])
        t = Thread(target = playsound, agrs = soundList[i])
        t.start()

listener = keyboard.Listener(on_release = onRelease)
listener.start()


listener.join()
