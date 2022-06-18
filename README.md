# Text-Editor-using-Queue-data-structure

## Implementation details:
Here, we implemented the text editor using Queue data structure in c language. We have created a menu driven program which interacts with the user and performs the operation accordingly. There are a total of four operations that can be performed in this program. For that there are ten methods. Each methods are explained below:

_## 1. examineFront:_

This function examines the front of the left and right queues and prints out the front of
the queue and the size of the queue.

_2. insertWord:_

This function takes a string as an argument and inserts each character of the string into
the queue.

_3. insertCharacter:_

This function inserts a character into the left queue.
**Parameter**: character (The character to be inserted)

_4. deleteCharacter:_

This function returns false if the rightQueue is empty, otherwise pop the rightQueue

_5. backSpaceCharacter:_

This function returns false if the leftQueue is empty, otherwise pop the leftQueue

_6. moveCursor:_

The function moves the cursor to the position specified by the user. Using moveLeft and
moveRight functions.

_7. moveLeft:_

This function moves the cursor to the left by the number of characters specified by the
user.

_8. moveRight:_

The function moves the cursor to the right by the specified number of characters
specified by the user.

_9. Display_text:_

The function takes the text from the left and right queues and displays it on the screen.

_10.findAndReplaceChar_

The function moves the cursor to the beginning of the text, then moves characters from
the right stack to the left stack and examines each character. If the character matches
the character to be replaced, the character is deleted and replaced with the new
character. If the character does not match, the character is moved to the left stack and
the cursor is moved to the right

**Parameter**: (findWhat) The character to be found
(replaceWith) The character to replace the found character with
