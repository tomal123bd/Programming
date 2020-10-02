'''
link https://stackoverflow.com/questions/50951955/pytesseract-tesseractnotfound-error-tesseract-is-not-installed-or-its-not-i/53672281
https://askubuntu.com/questions/1108884/ubuntu-18-04-error-install-tesseract
https://stackoverflow.com/questions/275018/how-can-i-remove-a-trailing-newline#:~:text=rstrip(%22%5Cr%5Cn,for%20python%202.2%20or%20later.&text=If%20your%20question%20is%20to,a%20new%20str(newstr).&text=to%20slice%20out%20your%20newline%20character.
https://medium.com/@MicroPyramid/extract-text-with-ocr-for-all-image-types-in-python-using-pytesseract-ec3c53e5fc3a
'''
from PIL import Image
from pytesseract import image_to_string

import pyautogui , time
# img_file=Image.open('/home/tomal/Desktop/c c++ problems/youtube_ad_skipper/ss.png')
# skip_ad_location=Image.open('/home/tomal/Desktop/c c++ problems/youtube_ad_skipper/sass.png')
# text = (image_to_string(Image.open('/home/tomal/Desktop/c c++ problems/youtube_ad_skipper/sass.png'), lang='eng'))
# im3 = pyautogui.screenshot(region=(785,545, 73, 20))
# im3.show()
while True:
    time.sleep(1)
    im = pyautogui.screenshot(region=(785,545, 73, 20))
    im.save('/home/tomal/Desktop/c c++ problems/youtube_ad_skipper/sass.png')
    text = (image_to_string(Image.open('/home/tomal/Desktop/c c++ problems/youtube_ad_skipper/sass.png'), lang='eng'))
    if text.rstrip() == "Skip Ads":
        pyautogui.rightClick((832, 556))
        #pyautogui.rightClick(('/home/tomal/Desktop/c c++ problems/youtube_ad_skipper/sass.png'))
