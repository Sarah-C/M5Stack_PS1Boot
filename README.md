# M5Stack_PS1Boot

Recreates a PS1 boot screen.

It takes only 343Kb (compressed) for this classic effect, so even on a small 4MB flash version of the M5Stack core, that leaves 91% free!

The 2 logos are PNG's converted to raw RBG565 via another online service, imageToCPP. https://javl.github.io/image2cpp/

I then used my online "Arduino PROGMEM file converter / creator V.1.0" to turn the Audacity 8 unsigned bit, 20,000 samples/s audio file into a header file for the Arduino IDE. https://codepen.io/SarahC/pen/dyWZLBG

It really needs the little orange blocks animating at the begining. The audio's run on CPU 2, so it wont mess up the audio speed when it's coded.
