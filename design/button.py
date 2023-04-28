"""
Run design files from root of the project.
"""

import matplotlib.pyplot as plt
import numpy as np
from PIL import Image

DESIGN_DOC = f"""
  UI Element - button.
    Clickable 2D HUD element with area with attached callback function, three render states and a label.
  1. Three render states - unfocused, focused, clicked
  2. Outside area
  3. Inside area
  4. In between areas there is a shading and light reflections
  5. Shading changes in response to a state change.

  Attachment: design png.
"""

def design():
    print(DESIGN_DOC)

if __name__ == "__main__":
    design()
    design_img = np.asarray(Image.open('design/button_design1.png'))
    plt.imshow(design_img)
    plt.show()

