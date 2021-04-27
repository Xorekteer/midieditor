import x_foxport

from foxutils import foxlaff
from foxutils import foxre
import os

import cv2
import numpy as np
import matplotlib.pyplot as plt

files = foxlaff.list_files_recursively(os.getcwd(), include_root=False)
files = foxre.relist("\.png", files)


for f in files:
    im = cv2.imread(f, -1)
    for i in range(im.shape[0]):
        for j in range(im.shape[1]):
            for k in range(3):      # opacity value left intact
                if im[i][j][k] < 20:
                    im[i][j][k] = 200
    cv2.imwrite(f, im)

