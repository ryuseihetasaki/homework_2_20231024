#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Enemy.h"
#include "Hero.h"
using namespace std;

// �R���X�g���N�^
Hero::Hero(char* pName, int hp) {

    // ���O���R�s�[
    _nameSize = strlen(pName);
    _pName = new char[_nameSize + 1];   // +1��\0��
    strcpy(_pName, pName);

    // ���̃p�����[�^������
    _hp = hp;
    _attack = 75;
    _diffence = 20;
}

// �f�X�g���N�^
Hero::~Hero() {
    if (_pName != NULL)
    {
        delete[] _pName;
        _pName = NULL;
    }
}

void Hero::show() {
    printf("���O�F%s\n", _pName);
    printf("�̗́F%d\n", _hp);
    printf("�U���́F%d, ", _attack);
    printf("�h��́F%d\n", _diffence);
}

void Hero::attack(Enemy* enemy) {
    int deffence = enemy->getDiffence();
    int damage = 0;
    damage = _attack - deffence;
    printf("%s�̍U���I\n%d�̃_���[�W��^����\n", _pName, damage);

    int hp = enemy->getHp();
    enemy->setHp(hp - damage);
    printf("����̎c��HP : %d\n", enemy->getHp());
}

void Hero::heal() {
    int healHp = 0;
    printf("�ǂ̂��炢�񕜂��܂���\n> ");
    cin >> healHp;
    _hp += healHp;

    printf("%s�̎c��HP : %d\n", _pName, _hp);
}
