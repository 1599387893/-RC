import os
import io 


if __name__ == '__main__':
    with io.open('Announcement.txt','a',encoding='utf-8') as f:
        print(f)
