# flappy-bird
My flappy bird clone.
I have challenged myself to not use any of the SFML View classes but still simulate the bird flying through the world past the pipes.
This is done by moving the pipes while the bird is in the same position in world/screen space. (apart from y, but it never goes offscreen)

To play, go to download folder and download the flappy bird 2.7z file

---notes---

-pipes and props use sf::Texture* as there is more than one instance of these objects but
the classes that actually hold and pass the textures (Game and Background) only have one instance

-no views were used, bird is always on screen and view never moves

-to texture pipes i split each one up into 2 parts (4 total), top and body, the top is the opening in the pipe and the body is the body.
i did this as sfml scaled the pipes wierldy and i wanted all the pipe openings to be the same size

-there may be one or two more additions if i get a nicer looking background texture


