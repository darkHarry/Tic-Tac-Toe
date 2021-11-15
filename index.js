import BOARD from './board.js';

/**
 * Creates a new player.
 * 
 * @param {string} name 
 * @param {string} symbol 
 * @returns 
 */
function createPlayer(name, symbol) {
    return {
        name,
        symbol
    };
}

const GAME_STATUS = ['PLAYING', 'DRAW', 'WIN'];

function APP(config) {
    const rounds = config.rounds || 3; 

    BOARD.create();

    const player1 = createPlayer('ABCD', BOARD.symbols.cross);
    const player2 = createPlayer('DCBA', BOARD.symbols.nought);

    while (rounds) {
        const turn = rounds&1;
        const player = (turn === 1) ? player1 : player2;

        let status = GAME_STATUS[0];

        while (status === GAME_STATUS[0]) {
            // get input from user
            // update BOARD
            // getBoardStatus and check for win / draw
            // update status
        }
        

        rounds -= 1;
    }
}

/*
const b = BOARD;
console.log(b);
console.log(b.create());
console.log(b.create());
console.log(b.update(0, 2, b.symbols.cross));
console.log(b.update(1, 2, b.symbols.nought));
console.log(b.getBoardStatus());
*/
