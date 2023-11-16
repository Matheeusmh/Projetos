const mario = document.querySelector('.mario');
const pipe = document.querySelector('.pipe');
const clouds = document.querySelector('.clouds');
const clouds2 = document.querySelector('.clouds2');
const gameover = document.querySelector('.gameover');
const scoreDisplay = document.querySelector('.score'); // Seleciona o elemento de exibição do placar
let score = 0; 
let counted = false;

const jump = () => {
    mario.classList.add('jump');

    setTimeout(() => {
        mario.classList.remove('jump');
    }, 500);
}

const loop = setInterval(() => {
    const pipePosition = pipe.offsetLeft;
    const cloudsPosition = clouds.offsetLeft;
    const clouds2Position = clouds2.offsetLeft;
    const marioPosition = +window.getComputedStyle(mario).bottom.replace('px', '');
    const gameoverPosition = +window.getComputedStyle(gameover).bottom.replace('px', '');

    console.log(pipePosition);

    if(pipePosition < 0 && marioPosition > 110 && !counted) {
        score++; 
        counted = true;
        scoreDisplay.textContent = `Score: ${score}`; // Atualiza o placar na tela
    }
    
    if(pipePosition > 120) {
        counted = false;
    }

    if (pipePosition <= 120 && pipePosition > 0 && marioPosition < 110) {
        pipe.style.animation = 'none';
        pipe.style.left = `${pipePosition}px`;

        mario.style.animation = 'none';
        mario.style.bottom = `${marioPosition}px`;

        mario.src = "./Imagens/game-over.png"
        mario.style.width = "75px";
        mario.style.marginLeft = "50px";


        clouds.style.animation = 'none';
        clouds.style.left = `${cloudsPosition}px`;

        clouds2.style.animation = 'none';
        clouds2.style.left = `${clouds2Position}px`;

        gameover.src = './Imagens/gameover.png';
        gameover.style.width = "400px";
        gameover.style.marginLeft = "50px";

        clearInterval(loop);
    }
    else {
        gameover.src = 'none';
        gameover.style.width = "400px";
        gameover.style.marginLeft = "50px";
    }
}, 10);


document.addEventListener('keydown', jump);
