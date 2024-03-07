# Welcome to PokeMock! (Work in Progress)
This is a small project attempting to mock basic elements from the well know game Pokemon! In this mock, I am using the SFML2 framework, which is able to handle a wide array of game based elements and mechanics, ranging from handling sprites and animations to basic game functionality such as movement and playability.

## Key Takeaways
Through this project, I learned alot about Game Development, from creating art to functionality, C++ best practices, and Object Oriented Programming. I am learning a lot about C++, especially about the very useful nature of pointers. In this project, there are many instances in which objects are very similar or multiple objects reference the same object (such is the case for tile sets and sprite sheets), and it would be highly inefficient to load a texture sheet or sprite sheet every single time, instead it can be loaded once, and then continuously referenced from there. I am also learning a lot about game development, before any step can be taken in development, there must be a lot of planning in both the game's design and functionality. I often find myself figuring out how best to structure objects for both optimal performance and playability. Through this, I am also learning quite a bit about OOP and how I can best structure objects to work with one another.

Thanks for taking the time to check out this project!

## Updates

## Added a Level Loading System (Loading Levels from TXT Files)
![txtFileLoadedLevel](https://github.com/yukiCodesStuff/pokemon_mock/assets/143112158/34046814-64e4-4818-9289-cddf6da1e1ca)

This is a map that was loaded from [this text file](https://github.com/yukiCodesStuff/pokemon_mock/blob/main/pokemock/maps/sampleMap.txt). We are now able to pass in a text file as a parameter when constructing the game world, making customizability much easier

## Added More Map Customization
![Screenshot 2024-03-06 193631](https://github.com/yukiCodesStuff/pokemon_mock/assets/143112158/3efa2ac8-990d-45a9-860d-508e7a5414d2)

Now able to add things such as trees to map, also have more tiles to choose from

### Recently completed adding a map!
![tileMapComplete](https://github.com/yukiCodesStuff/pokemon_mock/assets/143112158/d6360e7b-540a-4f85-a8fa-eaf745d5b828)

This map is not a set texture, but a collection of tileset sprites. Each of these tiles can be set to a certain texture, making it much more dynamic. Each of the tiles have a certain property indicating whether it is possibe to go through them or not. More functionality will be added in future changes (animations, more interactions, etc.)

## Best Resources
- [Getting Started](https://www.sfml-dev.org/tutorials/2.6/start-vc.php)
- [Setting up the Player Class](https://www.youtube.com/watch?v=qlpQu2btYC4&list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up&index=22)
- [Debugging a Compiler Issue](https://en.sfml-dev.org/forums/index.php?topic=20008.0)
- [Built off of this custom sprite sheet](https://www.pixilart.com/art/pokemon-trainer-cloudy-sprite-sheet-fa07ff878054bf3)
- [Tile Set for Map Creation](https://reliccastle.com/resources/15/)
