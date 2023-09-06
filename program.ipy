# Define the rooms
rooms = {
    'Hall': {
        'south': 'Kitchen',
        'west': 'Bathroom',
        'east': 'Bedroom'
    },
    'Kitchen': {
        'north': 'Hall',
        'item': 'keys'
    },
    'Bathroom': {
        'east': 'Hall'
    },
    'Bedroom': {
        'west': 'Hall',
        'item': 'wallet'
    }
}

# Start the player in the Hall
current_room = 'Hall'
inventory = []

# Loop until the player finds the keys and wallet
while True:
    # Show the current room and available exits
    print("You are in the " + current_room)
    exits = rooms[current_room].keys()
    for exit in exits:
        print("There is a door to the " + exit)

    # Show any items in the room
    if 'item' in rooms[current_room]:
        print("You see a " + rooms[current_room]['item'])

    # Ask the player for their next move
    move = input("Where do you want to go? ").lower()

    # Check if the move is valid
    if move in exits:
        current_room = rooms[current_room][move]
    elif move == 'take' and 'item' in rooms[current_room]:
        item = rooms[current_room]['item']
        inventory.append(item)
        print("You take the " + item)
        del rooms[current_room]['item']
    else:
        print("You can't go there.")

    # Check if the player has the keys and wallet
    if 'keys' in inventory and 'wallet' in inventory:
        print("You have found the keys and wallet! You win!")
        break
