# flappy-bird
My flappy bird clone.
I have challenged myself to not use any of the SFML View classes but still simulate the bird flying through the world past the pipes.
This is done by moving the pipes while the bird is in the same position in world/screen space. (apart from y, but it never goes offscreen)

---notes---
-pipes and props use sf::Texture* as there is more than one instance of these objects but
the classes that actually hold and pass the textures (Game and Background) only have one instance

-no views were used, bird is always on screen and view never moves

-there may be one or two more additions if i get a nicer looking background texture


