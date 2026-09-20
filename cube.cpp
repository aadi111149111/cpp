#include <iostream>
#include <vector>
#include <string>

using namespace std;

void drawCube(int size) {
    if (size < 2) return; // A cube needs a size of at least 2 to look like a shape

    int depth = size / 2;          // The 3D offset
    int height = size + depth;     // Total canvas height
    int width = size + depth;      // Total canvas width

    // Step 1: Create a blank canvas filled with spaces
    vector<string> grid(height, string(width, ' '));

    // Step 2: Setup drawing tools
    // Tool for horizontal lines
    auto drawHLine = [&](int r, int c, int len) {
        for (int i = 0; i < len; i++) grid[r][c + i] = '*';
    };

    // Tool for vertical lines
    auto drawVLine = [&](int r, int c, int len) {
        for (int i = 0; i < len; i++) grid[r + i][c] = '*';
    };

    // Tool for diagonal lines (draws from bottom-left going up-right)
    auto drawDiag = [&](int r, int c, int d) {
        for (int i = 0; i <= d; i++) grid[r - i][c + i] = '*';
    };

    // Step 3: Draw the Front Face
    drawHLine(depth, 0, size);             // Top edge
    drawHLine(height - 1, 0, size);        // Bottom edge
    drawVLine(depth, 0, size);             // Left edge
    drawVLine(depth, size - 1, size);      // Right edge

    // Step 4: Draw the Back Face (shifted up by 'depth' and right by 'depth')
    drawHLine(0, depth, size);             // Top edge
    drawHLine(size - 1, depth, size);      // Bottom edge
    drawVLine(0, depth, size);             // Left edge
    drawVLine(0, width - 1, size);         // Right edge

    // Step 5: Connect the four corners with diagonals
    drawDiag(depth, 0, depth);             // Top-Left corner
    drawDiag(height - 1, 0, depth);        // Bottom-Left corner
    drawDiag(depth, size - 1, depth);      // Top-Right corner
    drawDiag(height - 1, size - 1, depth); // Bottom-Right corner

    // Step 6: Print the completed canvas to the console
    for (int i = 0; i < height; i++) {
        cout << grid[i] << "\n";
    }
}

int main() {
    int cubeSize = 8;
    cout << "Drawing a cube of size " << cubeSize << ":\n\n";
    drawCube(cubeSize);
    
    return 0;
}