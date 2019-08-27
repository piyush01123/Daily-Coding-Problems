
import cv2

img = cv2.imread('jp.png')
tetris = cv2.imread('tetris_blocks.png')


def resize(img, size=(400, 100)):
    """
    Resize Image without taking care of the aspect ratio
    """
    resized = cv2.resize(img, size)
    cv2.imwrite('resized.jpg', resized)


def resize_with_AR(img, width=400):
    """
    Resize Image taking care of the aspect ratio
    """
    # Remember img.shape is (H, W, C)
    ar = img.shape[0]/img.shape[1] #H/W
    # cv2.resize wants (w, h)
    resized = cv2.resize(img, (width, int(ar*width)))
    cv2.imwrite('resize_with_AR.jpg', resized)


#All translations and rotations are affine transformations.
def translate(img):
    """
    Translate Image
    """
    pass


def rotate(img):
    """
    Rotate image about center by theta counter-clockwise
    """
    pass

def rotate_full(img):
    """
    Rotate image without distorting size.
    """
    pass

def threshold(img):
    """
    Translate Image
    """
    pass

def detect_countour(img):
    """
    Translate Image
    """
    pass

def erode_dilate(img):
    """
    Translate Image
    """
    pass

def mask_and_bitwise_ops(img):
    """
    Translate Image
    """
    pass

def convolution(img):
    """
    Apply convolution operation
    """
    pass

def edge_detection(img):
    pass


if __name__=='__main__':
    resize(img)
    resize_with_AR(img)
    rotate(img)
    rotate_full(img)
    threshold(img)
    detect_countour(img)
    erode_dilate(img)
    mask_and_bitwise_ops(img)
    convolution(img)
    edge_detection(img)
