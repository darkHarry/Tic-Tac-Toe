const BOARD = (function() {
    /* Private Members */
    const _board = [];

    function _isBoardInit() {
        return _board.length !== 0;
    }

    /* Public Members */
    const SYMBOLS = {
        cross: 'X',
        nought: 'O'
    };

    /**
     * initializes the board once.
     * 
     * @returns {boolean} - create status
     */
    function create() {
        // If board not initialized
        if (!_isBoardInit()) {
            _board.push([null, null, null]);
            _board.push([null, null, null]);
            _board.push([null, null, null]);

            return true;
        }

        return false;
    }

    /**
     * updates the board values.
     * 
     * @param {number} row - row index of the board
     * @param {number} col - col index of the row
     * @param {string} symbol - one of the values in SYMBOLS
     * 
     * @return {boolean} - update status
     */
    function update(row, col, symbol) {
        // _board not initialized
        if (!_isBoardInit()) return false;

        // validate row and col as integers
        if (!Number.isInteger(row) || !Number.isInteger(col)) return false;

        const [ rows, cols ] = [_board.length, _board[0].length];
        // Out of index validation
        if (row < 0 || row >= rows || col < 0 || col >= cols) return false;

        // Already filled
        if (_board[row][col] !== null) return false;

        // Invalid symbol (not present in SYMBOLS)
        const SYMBOL_VALUES = Object.values(SYMBOLS);
        if (SYMBOL_VALUES.includes(symbol) === false) return false;

        _board[row][col] = symbol;
        return true;
    }

    /**
     * resets the board.
     * 
     * @returns {boolean} - reset status
     */
    function reset() {
        if (_isBoardInit()) {
            // For each row
            _board.forEach(row => {
                // For each cell in a row
                for (let i = 0; i < row.length; i++) {
                    row[i] = null;
                }
            });
            return true;
        }
        return false;
    }

    /**
     * returns board status.
     * 
     * @returns {Array} - Board
     */
    function getBoardStatus() {
        if (!_isBoardInit()) return [];

        let currentBoard = [];

        // For each row of _board
        _board.forEach(row => {
            currentBoard.push([]);
            const lastRowIndex = currentBoard.length - 1;

            for (let i = 0; i < row.length; i++) {
                currentBoard[lastRowIndex].push(row[i]);
            }
        });

        return currentBoard;

    }

    return {
        symbols: SYMBOLS,
        create,
        update,
        reset,
        getBoardStatus
    };

}());

export default BOARD;