string checkNeighbors(int array[10][3], int row, int col) {
    // Checks if coordinates are valid
    if (row < 0 || row >= 10 || col < 0 || col >= 3) {
        return "Invalid coordinates";
    }

    // Checks if the coordinate to the left is 0
    if (col > 0 && array[row][col - 1] == 0) {
        return "fail";
    }

    // Checks if the coordinate to the right is 0
    if (col < 2 && array[row][col + 1] == 0) {
        return "fail";
    }

    // If no surronding coordinates have a value of 0
    return "success";
}