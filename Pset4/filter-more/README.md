### Task: ###
**Implement a program that applies filters to BMP image files.**

### Specification: ###
**Image Filtering:**
Taking pixels of original image and modifying each pixel in such a way that a particular effect is apparent in resulting image.

This practice comprises of implementation of 4 filters types:
- `Grayscale`
- `Reflection`
- `Blur`
- `Edges`

Practice Question Source: [More Info](https://cs50.harvard.edu/x/2022/psets/4/filter/more/)

### Usage: ###

To run program, user can run following commands in codespace terminal:

1. `cd Pset4`
2. `cd filter-more`
3. `make filter`
4. `./filter [filter] [original BMP image file] [output BMP image file]` (Eg. `./filter -r images/IMAGE.bmp images/REFLECTED.bmp`)<br>
(*Note:* `-b`: Blur filter ; `-e` : Edges filter ; `-g` : Grayscale filter ; `-r`  : Reflection filter)

### Program Example: ###
**Original Image**

![Original image courtyard](/../main/Pset4/filter-more/images/courtyard.bmp)

**Blur filter**

![image](https://user-images.githubusercontent.com/107826905/213721219-f507f04c-7f4c-4f73-886a-2b9b305d596b.png)

**Edges filter**

![image](https://user-images.githubusercontent.com/107826905/213721799-7bd46df0-9b33-4544-8355-64732440ece5.png)

**Grayscale filter**

![image](https://user-images.githubusercontent.com/107826905/213721978-2012539e-da3b-4162-b791-828cd13c0e51.png)

**Reflection filter**

![image](https://user-images.githubusercontent.com/107826905/213722057-bc347f2f-817d-4c09-bfa4-66861e4d1e60.png)
