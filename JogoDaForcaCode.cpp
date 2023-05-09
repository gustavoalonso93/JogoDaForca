#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    const int MAX_TENTATIVAS = 6;
    vector<string> palavras = {"abacaxi", "banana", "laranja", "morango", "uva"};
    string palavraSecreta = palavras[rand() % palavras.size()];
    string palavraEscondida(palavraSecreta.size(), '_');
    int tentativasRestantes = MAX_TENTATIVAS;

    cout << "Bem-vindo ao jogo da forca!" << endl;
    cout << "A palavra secreta tem " << palavraSecreta.size() << " letras." << endl;

    while (tentativasRestantes > 0 && palavraEscondida != palavraSecreta) {
        cout << "Você tem " << tentativasRestantes << " tentativas restantes." << endl;
        cout << "Palavra: " << palavraEscondida << endl;
        cout << "Digite uma letra: ";

        char letra;
        cin >> letra;

        bool acertou = false;
        for (int i = 0; i < palavraSecreta.size(); ++i) {
            if (palavraSecreta[i] == letra) {
                palavraEscondida[i] = letra;
                acertou = true;
            }
        }

        if (acertou) {
            cout << "Parabéns, você acertou uma letra!" << endl;
        } else {
            cout << "Não foi dessa vez..." << endl;
            --tentativasRestantes;
        }
    }

    if (palavraEscondida == palavraSecreta) {
        cout << "Parabéns, você ganhou o jogo da forca!" << endl;
    } else {
        cout << "Você perdeu o jogo da forca. A palavra secreta era: " << palavraSecreta << endl;
    }

    return 0;
}
