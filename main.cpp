#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <string>
//#include <windows.h>
//#include<conio.h>
//#include<dos.h>
#include <time.h>
#include <string>

using namespace std;

//Effect
class Effect {
public:


};

//CARD
class Card {
protected:
    string cardName;
    string manaCost;
    string cardColor;
    bool tapp = false;
    string cardType = "non-set";



public:
     virtual void play() {}

     void setTapped(bool t) {
        tapp = t;
    }

     bool isTapped() {
        return tapp;
    }

    string getManaCost() {
       return manaCost;
    }

    string getCardName() {
        return cardName;
    }
    string getCardColor() {
        return cardColor;
    }
    string getCardType() {
        return cardType;
    }


};



class enchantmentCard : public Card {
protected:
    Effect effect;
public:
    enchantmentCard(string cN, string mC, string cC, Effect ef) : effect(ef) {
        cardName = cN;
        manaCost = mC;
        cardColor = cC;
        cardType = "Enchantment";
    };

     void play() {
        cout << "enchantment played" << endl;
    }


};



class sorceryCard : public Card {
protected:
//    unique_ptr<Effect> effect = make_unique<Effect>();
    Effect effect;
//    unique_ptr<Effect> effects;
public:
    sorceryCard(string cN, string mC, string cC,
                Effect ef) {
        cardName = cN;
        manaCost = mC;
        cardColor = cC;
        effect = ef;
        cardType = "Sorcery";
    };

    void play() {
        cout << "sorcery played" << endl;
    }


};

class creatureCard : public Card {
protected:
    int attackPower;
    int HP;
    string ability;
    bool isDestroyed = false;
    vector<enchantmentCard> enchantmentCards;
    vector<sorceryCard> sorceryCards;

public:
    creatureCard(string cN, string cC, int aP, int hp, string ab, string mC) :
            attackPower(aP),
            HP(hp),
            ability(ab) {

        cardName = cN;
        manaCost = mC;
        cardColor = cC;
        cardType = "Creature";

        if (HP <= 0) {
            isDestroyed = true;
        }

    };

    void play() {
        cout << "creature played" << endl;
    }


    bool getIsDestroyed() {
        return isDestroyed;
    }

    int getHP () {
        return HP;
    }

    void setHP(int hp) {
        HP += hp;
        if(HP <= 0) {
            isDestroyed = true;
        }
    }
    int getAttackPower() {
        return attackPower;
    }
    void setAttackPower(int ap) {
        attackPower += ap;
    }
    string getAbility() {
        return ability;
    }
    void setAbility(string ab) {
        ability = ab;
    }
    void setIsDestroyed () {
        isDestroyed = true;
        HP = 0;
    }

    void addSorceryCard(sorceryCard c){
        sorceryCards.push_back(c);
    }
    void addEnchantmentCard(enchantmentCard c){
        enchantmentCards.push_back(c);
    }
    void removerSorceryCard() {
        sorceryCards.pop_back();
    }
    void removeEnchantmentCard(){
        enchantmentCards.pop_back();
    }


};

class landCard : public Card {
protected:
    string manaCost = "0";
    bool isSelected = false;
    string manaType;


public:

    landCard(string cN,string mType) {
        cardName = cN;
        manaType = mType;
        cardType = "Land";
    }


    string getManaType () {
        return manaType;
    }

    void play() {
        cout << "land played" << endl;
    }


};

class Player{
protected:
    string name;
    int HP;
    int Gmana = 0;
    int Lmana = 0;
    int Rmana = 0;
    int Wmana = 0;
    int Bmana = 0;
    int colorlessMana = 0;
    bool playersTurn = false;

    //Hand

    vector<creatureCard> handCreatureCards;
    vector<enchantmentCard> handEnchantmentCards;
    vector<sorceryCard> handSorceryCards;
    vector<landCard> handLandCards;

    //In Play

    vector<creatureCard> inPlayCreatureCards;
    vector<sorceryCard> inPlaySorceryCards;
    vector<enchantmentCard> inPlayEnchantmentCards;
    vector<landCard> inPlayLandCards;


    //Discard
    vector<creatureCard> DiscardCreatureCards;
    vector<sorceryCard> DiscardSorceryCards;
    vector<enchantmentCard> DiscardEnchantmentCards;
    vector<landCard> DiscardLandCards;

    //Library
    vector<creatureCard> LibraryCreatureCards;
    vector<sorceryCard> LibrarySorceryCards;
    vector<enchantmentCard> LibraryEnchantmentCards;
    vector<landCard> LibraryLandCards;

    vector<Card> Deck;


    //

    vector<creatureCard> creatureCards;
    vector<landCard> landCards;
    vector<sorceryCard> sorceryCards;
    vector<enchantmentCard> enchantmentCards;


public:
    Player(string n) {
        HP = 15;
        name = n;
    }

    string getName() {
        return name;
    }

    int getHP() {
        return HP;
    }
    void setHP(int hp) {
        HP = hp;
    }

    void destroyLandCard() {
//        landCards.pop_back();
    }

    void destroyCreatureCard(){
//        PlayerCreatureCards->pop_back();
    }

    //CREATURE CARDS

    vector<creatureCard> getLibraryCreatureCards(){
        return LibraryCreatureCards;
    }
    vector<creatureCard> getHandCreatureCards(){
        return handCreatureCards;
    }
    vector<creatureCard> getCreatureCards(){
        return creatureCards;
    }

    vector<creatureCard> getDiscardCreatureCards(){
        return DiscardCreatureCards;
    }

    vector<creatureCard> getInPlayCreatureCards(){
        return inPlayCreatureCards;
    }
    void AddLibraryCreatureCards(creatureCard c){
         LibraryCreatureCards.push_back(c);
    }
    void AddHandCreatureCards(creatureCard c){
        LibraryCreatureCards.push_back(c);
    }
    void AddInPlayCreatureCards(creatureCard c){
        LibraryCreatureCards.push_back(c);
    }
    void AddDiscardCreatureCards(creatureCard c){
        DiscardCreatureCards.push_back(c);
    }

    //LAND CARDS
    vector<landCard> getLibraryLandCards(){
        return LibraryLandCards;
    }
    vector<landCard> getHandLandCards(){
        return handLandCards;
    }
    vector<landCard> getLandCards(){
        return landCards;
    }

    vector<landCard> getDiscardLandCards(){
        return DiscardLandCards;
    }

    vector<landCard> getInPlayLandCards(){
        return inPlayLandCards;
    }
    void AddLibraryLandCards(landCard c){
        LibraryLandCards.push_back(c);
    }
    void AddHandLandCards(landCard c){
        handLandCards.push_back(c);
    }
    void AddInPlayLandCards(landCard c){
        inPlayLandCards.push_back(c);
    }
    void AddDiscardCreatureCards(landCard c){
        DiscardLandCards.push_back(c);
    }

    //SORCERY CARDS
    vector<sorceryCard> getLibrarySorceryCards(){
        return LibrarySorceryCards;
    }
    vector<sorceryCard> getHandSorceryCards(){
        return handSorceryCards;
    }
    vector<sorceryCard> getSorceryCards(){
        return sorceryCards;
    }

    vector<sorceryCard> getDiscardSorceryCards(){
        return DiscardSorceryCards;
    }

    vector<sorceryCard> getInPlaySorceryCards(){
        return inPlaySorceryCards;
    }
    void AddLibrarySorceryCards(sorceryCard c){
        LibrarySorceryCards.push_back(c);
    }
    void AddHandSorceryCards(sorceryCard c){
        handSorceryCards.push_back(c);
    }
    void AddInPlaySorceryCards(sorceryCard c){
        inPlaySorceryCards.push_back(c);
    }
    void AddDiscardSorceryCards(sorceryCard c){
        DiscardSorceryCards.push_back(c);
    }

    //ENCHANTMENT CARDS
    vector<enchantmentCard> getLibraryEnchantmentCards(){
        return LibraryEnchantmentCards;
    }
    vector<enchantmentCard> getHandEnchantmentCards(){
        return handEnchantmentCards;
    }
    vector<enchantmentCard> getEnchantmentCards(){
        return enchantmentCards;
    }

    vector<enchantmentCard> getDiscardEnchantmentCards(){
        return DiscardEnchantmentCards;
    }

    vector<enchantmentCard> getInPlayEnchantmentCards(){
        return inPlayEnchantmentCards;
    }
    void AddLibraryLandCards(enchantmentCard c){
        LibraryEnchantmentCards.push_back(c);
    }
    void AddHandEnchantmentCards(enchantmentCard c){
        handEnchantmentCards.push_back(c);
    }
    void AddInPlayEnchantmentCards(enchantmentCard c){
        inPlayEnchantmentCards.push_back(c);
    }
    void AddDiscardEnchantmentCards(enchantmentCard c){
        DiscardEnchantmentCards.push_back(c);
    }

    void printInHandInfo() {
        vector<landCard>::iterator a;
        vector<creatureCard>::iterator b;
        vector<enchantmentCard>::iterator c;
        vector<sorceryCard>::iterator d;

        cout << name << "'s" <<" hand: " << endl;

        cout<<"Creature Cards: " << endl;
        for(b = handCreatureCards.begin(); b<handCreatureCards.end(); b++) {
            cout << b->getCardName() << ", ";
        }
        cout <<"Land Cards: " << endl;
        for(a = handLandCards.begin(); a<handLandCards.end(); a++) {
            cout << a->getCardName() << ", ";
        }
        cout <<"Enchantment Cards: " << endl;
        for(c = handEnchantmentCards.begin(); c<handEnchantmentCards.end(); c++) {
            cout << c->getCardName() << ", ";
        }
        cout << "Sorcery Cards" << endl;
        for(d = handSorceryCards.begin(); d<handSorceryCards.end(); d++) {
            cout << d->getCardName() << ", ";
        }
    }

    void printInPlay() {
        vector<landCard>::iterator a;
        vector<creatureCard>::iterator b;
        vector<enchantmentCard>::iterator c;
        vector<sorceryCard>::iterator d;

        cout << "InPlay: " << endl;

        cout<<"Creature Cards: " << endl;
        for(b = inPlayCreatureCards.begin(); b<inPlayCreatureCards.end(); b++) {
            cout << b->getCardName() << ", ";
        }
        cout <<"Land Cards: " << endl;
        for(a = inPlayLandCards.begin(); a<inPlayLandCards.end(); a++) {
            cout << a->getCardName() << ", ";
        }
        cout <<"Enchantment Cards: " << endl;
        for(c = inPlayEnchantmentCards.begin(); c<inPlayEnchantmentCards.end(); c++) {
            cout << c->getCardName() << ", ";
        }
        cout << "Sorcery Cards" << endl;
        for(d = inPlaySorceryCards.begin(); d<inPlaySorceryCards.end(); d++) {
            cout << d->getCardName() << ", ";
        }
        cout << endl;
    }




    void AddCreatureCards(creatureCard c){
        creatureCards.push_back(c);
        handCreatureCards.push_back(c);
        inPlayCreatureCards.push_back(c);
    }

    void AddSorceryCards(sorceryCard c){
        sorceryCards.push_back(c);
        handSorceryCards.push_back(c);
        inPlaySorceryCards.push_back(c);
    }
    void AddEnchantmentCards(enchantmentCard c){
        enchantmentCards.push_back(c);
        handEnchantmentCards.push_back(c);
        inPlayEnchantmentCards.push_back(c);
    }
    void AddLandCards(landCard c){
        landCards.push_back(c);
        handLandCards.push_back(c);
        inPlayLandCards.push_back(c);
    }

    void addDeck(Card c) {
        Deck.push_back(c);
    }
    vector<Card> getDeck() {
        return Deck;
    }
    void printDeck() {
        vector<enchantmentCard>::iterator vPtr;
        vector<sorceryCard>::iterator i;
        vector<landCard>::iterator l;
        vector<creatureCard>::iterator c;

        for(vPtr = enchantmentCards.begin(); vPtr < enchantmentCards.end(); vPtr++){

            cout << vPtr->getCardName() << " , ";
        }
        cout << endl;
        for(i = sorceryCards.begin(); i < sorceryCards.end(); i++){

            cout << i->getCardName() << " , ";
        }
        cout << endl;
        for(l = landCards.begin(); l < landCards.end(); l++){

            cout << l->getCardName() << " , ";
        }
        cout << endl;
        for(c = creatureCards.begin(); c < creatureCards.end(); c++){

            cout << c->getCardName() << " , ";
        }
        cout << endl;
    }


    void AddMana(int m,string manaType) {
        if(manaType == "G") {
            Gmana +=m;
            colorlessMana +=m;
        } else if (manaType == "L") {
            Lmana +=m;
            colorlessMana +=m;
        }
        else if (manaType == "R") {
            Rmana +=m;
            colorlessMana +=m;
        }
        else if (manaType == "B") {
            Bmana +=m;
            colorlessMana +=m;
        }
        else if (manaType == "W") {
            Wmana +=m;
            colorlessMana +=m;
        } else {
            colorlessMana +=m;
        }
    }

    int getGMana () {
        return Gmana;
    }
    int getLMana () {
        return Lmana;
    }
    int getRMana () {
        return Rmana;
    }
    int getBMana () {
        return Bmana;
    }
    int getWMana () {
        return Wmana;
    }
    int getColorLessMana() {
        return colorlessMana;
    }

    void setGMana (int m) {
        Gmana += m;
    }
    void setLMana (int m) {
        Lmana += m;
    }
    void setRMana (int m) {
        Rmana += m;
    }
    void setBMana (int m) {
        Bmana += m;
    }
    void setWMana (int m) {
        Wmana += m;
    }
    void setColorlessMana(int m) {
        colorlessMana += m;
    }

    void setPlayerTurn(bool t) {
        playersTurn = t;
    }
    bool isPlayersTurn() {
        return playersTurn;
    }

    int getHandCount() {
        int handCount;
        handCount = handSorceryCards.size()+
                handCreatureCards.size()+
                handEnchantmentCards.size()+
                handLandCards.size();

        return handCount;
    }
    int getLibraryCount() {
        int libraryCount;
        libraryCount = LibrarySorceryCards.size()+
                    LibraryCreatureCards.size()+
                    LibraryEnchantmentCards.size()+
                    LibraryLandCards.size();

        return libraryCount;
    }

};


//Sorcery Cards effects
class DestroyCreatureEffect:public Effect {
public:
    void effect(unique_ptr<creatureCard>&t) {
        t->setIsDestroyed();
    }
};



class DealTwoDamageCreatureOrPlayer : public Effect {
public:
    void effect(unique_ptr<Player>&p) {
        int HP = p->getHP();
        p->setHP(HP - 2);
    }
    void effectPlayer(unique_ptr<creatureCard>&c) {
        int HP = c->getHP();
        c->setHP(HP - 2);
    }
};

class DestroyOneTargetEnchantment : public Effect {
public:
    void effect(unique_ptr<creatureCard>&c) {
        c->removeEnchantmentCard();
    }

};

class DestroyOneTargetLand : public Effect {
public:
    void effect(unique_ptr<Player>&c) {
        c->destroyLandCard();
    }
};
class OneCharacterCardDiscardToHand : public Effect {
    void effect(vector<Card> hand,vector<Card> discard) {
        hand.push_back(discard.back());
        discard.pop_back();
        cout <<"Discard to hand effect is used" << endl;
    }
};

class DealOneDamageToAllCreatures : public Effect {
    void effect(vector<creatureCard> p) {
        vector<creatureCard>::iterator vPtr;

        for(vPtr = p.begin(); vPtr < p.end(); vPtr++){

            vPtr->setHP(- 1);
        }
        cout <<"Attack to creatures effect is used" << endl;
    }
};

class DestroyOneTargetCreature : public Effect {
    void effect(unique_ptr<Player>&p) {
        p->destroyCreatureCard();
    }
};



// Enchantment Cards effects
class OneTargetCreatureGainsTrample : public Effect {
    void effect(unique_ptr<creatureCard>&c){
        c->setAbility("Trample");
    }
};

class AllWhiteCreaturesGainP1P1 : public Effect {
    void AllWhiteCreaturesGainP1P1Effect(vector<creatureCard> p) {
        vector<creatureCard>::iterator vPtr;

        for(vPtr = p.begin(); vPtr < p.end(); vPtr++){

            if(vPtr->getCardColor() == "White"){
                vPtr->setHP(  1);
                vPtr->setAttackPower(1);
            }
        }
        cout <<"All white creatures gain attack damage effect is used" << endl;
    }
};

class AllBlackCreaturesGainM1M1 : public Effect {
    void AllBlackCreaturesGainM1M1Effect(shared_ptr<vector<creatureCard>> p) {
        vector<creatureCard>::iterator vPtr;

        for(vPtr = p->begin(); vPtr < p->end(); vPtr++){

            if(vPtr->getCardColor() == "Black"){
                vPtr->setHP(  -1);
                vPtr->setAttackPower(-1);
            }
        }
        cout <<"All black creatures gain attack damage effect is used" << endl;
    }
};
class AllBlackCreaturesGainP2P0 : public Effect {
    void AllBlackCreaturesGainP2P0Effect(shared_ptr<vector<creatureCard>> p) {
        vector<creatureCard>::iterator vPtr;

        for(vPtr = p->begin(); vPtr < p->end(); vPtr++){

            if(vPtr->getCardColor() == "Black"){
                vPtr->setAttackPower(+2);
            }
        }
        cout <<"All black creatures gain attack damage effect is used" << endl;
    }
};
class AllGreenCreaturesLoseTrample : public Effect {
public:
     void AllGreenCreaturesLoseTrampleEffect(shared_ptr<vector<creatureCard>> p){
        vector<creatureCard>::iterator vPtr;

        for(vPtr = p->begin(); vPtr < p->end(); vPtr++){

            if(vPtr->getCardColor() == "Green"){
                vPtr->setAbility("");
            }
        }
        cout <<"All green creatures lose trample effect is used" << endl;
    }
};
class OneTargetCreatureLosesFirstStrike : public Effect {
public:

        void OneTargetCreatureLosesFirstStrikeEffect(shared_ptr<vector<creatureCard>> p){
            vector<creatureCard>::iterator vPtr;

            for(vPtr = p->begin(); vPtr < p->end(); vPtr++){

                if(vPtr->getAbility() == "First Strike"){
                    vPtr->setAbility("");
                }
            }
            cout <<"Target creature lost first strike effect" << endl;
        }

};


//OPTIONAL
//class colorCost {};

static void manaErrorMessage() {
    cout << "Not enough mana to play this card!" << endl;
}



class colorCost {
public:
    bool isPlayable = false;


    bool colorCostCreatureCard(shared_ptr<creatureCard>&c,unique_ptr<Player>&p) {
        string manaCost = c->getManaCost();

        if(manaCost == "W") {
            if(p->getWMana() >= 1) {
                p->setWMana(-1);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "1W") {
            if(p->getWMana() >= 1 ) {
                p->setWMana(-1);
                p->setColorlessMana(-1);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "WW") {
            if(p->getWMana() >= 2) {
                p->setWMana(-2);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "2G") {
            if(p->getGMana() >= 1) {
                p->setGMana(-1);
                p->setColorlessMana(-2);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "2WW") {
            if(p->getWMana() >= 2) {
                p->setGMana(-2);
                p->setColorlessMana(-2);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "2GW") {
            if(p->getWMana() >= 1 && p->getGMana() >= 1 ) {
                p->setGMana(-1);
                p->setWMana(-1);
                p->setColorlessMana(-2);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "B") {
            if(p->getBMana() >= 1) {
                p->setBMana(-1);
                isPlayable = true;

            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "1B") {
            if(p->getBMana() >= 1) {
                p->setBMana(-1);
                p->setColorlessMana(-1);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "BB") {
            if(p->getBMana() >= 2) {
                p->setBMana(-2);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "2R") {
            if(p->getRMana() >= 1) {
                p->setRMana(-1);
                p->setColorlessMana(-2);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "1RB") {
            if(p->getRMana() >= 1 && p->getBMana() >= 1) {
                p->setRMana(-1);
                p->setBMana(-1);
                p->setColorlessMana(-1);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "3B") {
            if( p->getBMana() >= 3) {
                p->setBMana(-3);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        return isPlayable;
    }

    bool colorCostSorceryCard(shared_ptr<sorceryCard>&c,shared_ptr<Player>&p) {
        string manaCost = c->getManaCost();

        if(manaCost == "1W") {
            if(p->getWMana() >= 1) {
                p->setWMana(-1);
                p->setColorlessMana(-1);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "1G") {
            if(p->getGMana() >= 1 ) {
                p->setGMana(-1);
                p->setColorlessMana(-1);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "1GW") {
            if(p->getGMana() >= 1 && p->getWMana()>=1 ) {
                p->setGMana(-1);
                p->setWMana(-1);
                p->setColorlessMana(-1);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "B") {
            if(p->getBMana() >= 1 ) {
                p->setBMana(-1);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "2B") {
            if(p->getBMana() >= 1 ) {
                p->setBMana(-1);
                p->setColorlessMana(-2);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "1B") {
            if(p->getBMana() >= 1 ) {
                p->setBMana(-1);
                p->setColorlessMana(-1);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        return  isPlayable;
    }

    bool colorCostEnchantmentCard(shared_ptr<enchantmentCard>&c, shared_ptr<Player>&p) {
        string manaCost = c->getManaCost();

        if(manaCost == "G") {
            if(p->getGMana() >= 1) {
                p->setGMana(-1);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "1W") {
            if(p->getWMana() >= 1 ) {
                p->setWMana(-1);
                p->setColorlessMana(-1);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "1B") {
            if(p->getBMana() >= 1 ) {
                p->setBMana(-1);
                p->setColorlessMana(-1);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "2R") {
            if(p->getRMana() >= 1 ) {
                p->setRMana(-1);
                p->setColorlessMana(-1);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }
        else if(manaCost == "B") {
            if(p->getBMana() >= 1 ) {
                p->setBMana(-1);
                isPlayable = true;
            } else {
                manaErrorMessage();
                isPlayable = false;
            }
        }

        return isPlayable;
    }
};



void AttackToCard(creatureCard&attacker,unique_ptr<Player>&attackerPlayer,unique_ptr<Player>&defencePlayer,creatureCard&defenceCard) {
    double excessAP;
//        if(attacker.isTapped()) {

            if(attacker.getAbility() == "Trample") {
                excessAP = attacker.getAttackPower() - defenceCard.getHP();
                defenceCard.setHP(-excessAP);
                cout << attacker.getCardName() << "used Trample ability" << endl;

            } else if (attacker.getAbility() == "First Strike") {
                if(defenceCard.getAbility() == "First Strike") {
                    defencePlayer->setHP(-defenceCard.getAttackPower());
                    defenceCard.setHP(-attacker.getAttackPower());
                    cout << attacker.getCardName() << "used First Strike ability" << endl;
                    cout << defenceCard.getCardName() << "also used First Strike ability and blocked effect" << endl;
                } else {
                    attacker.setHP(-defenceCard.getAttackPower());
                    if(defenceCard.getHP() <= 0 ) {
                        cout << defenceCard.getCardName() << "is destroyed" << endl;
                        defenceCard.setIsDestroyed();
                    } else {
                        defenceCard.setHP(-attacker.getAttackPower());
                    }
                }
            } else {
                attacker.setHP(-defenceCard.getAttackPower());
                defenceCard.setHP(-attacker.getAttackPower());
            }
                cout << defenceCard.getCardName() <<  "get "
                 << excessAP <<" damage from" << attacker.getCardName()
                 << " card." <<endl;
                cout <<  defenceCard.getCardName()  << "'s current hp is" <<
                 defencePlayer->getHP() << endl;
            }
//        }



void playLandCard(landCard&c, unique_ptr<Player>&p){
    string type = c.getManaType();
    p->AddMana(1,type);
}
//
//void playSorceryCard(sorceryCard&c, unique_ptr<Player>&p,Effect ef){
//
//}



void AttackToPlayer(creatureCard&attacker, unique_ptr<Player>&defencePlayer) {
//        if(attacker.isTapped()) {
            defencePlayer->setHP(-attacker.getAttackPower());
            cout << attacker.getCardName() << " is attacked " << defencePlayer->getName() << endl;
            cout << defencePlayer->getName() << " get " << attacker.getAttackPower() << " damage" << endl;
//        }

}


//Four card piles


void EndPhase(unique_ptr<Player>&p) {
    p->setColorlessMana(0);
    p->setWMana(0);
    p->setBMana(0);
    p->setLMana(0);
    p->setRMana(0);
}

void Draw(unique_ptr<Player>&p,string cardType) {
//    if(!(p->size() <=0 )) {
//        if(h.size() <= 7) {
//            h.push_back(l.back());
//        }
//    } else {
//        cout << "Game is over" <<endl;
//    }
    if(p->getLibraryCount() <= 0 || p->getHandCount() <= 7){

        cout << p->getName() << " lost the game" << endl;
    } else {
        if(cardType == "Creature") {
            p->AddHandCreatureCards(p->getLibraryCreatureCards().back());
        } else if(cardType == "Land") {
            p->AddHandLandCards(p->getLibraryLandCards().back());
        } else if(cardType == "Enchantment") {
            p->AddHandCreatureCards(p->getLibraryCreatureCards().back());
        } else if (cardType == "Sorcery") {
            p->AddHandSorceryCards(p->getLibrarySorceryCards().back());
        }
    }

}

void unTapp(shared_ptr<vector<Card>>&c) {
    vector<Card>::iterator i;
    for(i = c->begin(); i < c->end(); i++) {
        i->setTapped(false);
    }
}


int main() {
    colorCost checkColorCost;

    //Land cards


landCard Forest ("Forest", "G");

//landCard Forest("Forest", "G");
landCard Island ("Island", "L");
landCard Mountain("Mountain","R");
landCard Plains("Plains","W");
landCard Swamp("Swamp","B");

////Creature Cards
//
creatureCard Soldier("Soldier","White",1,1,"non-set","W");
creatureCard Armored_Pegasus("Armored Pegasus","White",1,2,"non-set","1W");
creatureCard White_Knight("White Knight","White",2,2,"First Strike","WW");
creatureCard Angry_Bear("Angry Bear","Green",3,2,"Trample","2G");
creatureCard Guard("Guard","White",2,5,"non-set","2WW");
creatureCard Werewolf("Werewolf","Green",4,6,"Trample","2GW");
creatureCard Skeleton("Skeleton","Black",1,1,"non-set","B");
creatureCard Ghost("Ghost","Black",2,1,"non-set","1B");
creatureCard Black_Knight("Black Knight","Black",2,2,"First Strike","BB");
creatureCard Orc_Maniac("Orc Maniac","Red",4,1,"non-set","2R");
creatureCard Hobgoblin("Hobgoblin","Red",3,3,"non-set","1RB");
creatureCard Vampire("Vampire","Black",6,3,"non-set","3B");

//Effects
DestroyOneTargetEnchantment destroyOneTargetEnchantment;
DestroyCreatureEffect destroyCreatureEffect;
DealTwoDamageCreatureOrPlayer dealTwoDamageCreatureOrPlayer;
DestroyOneTargetLand destroyOneTargetLand;
DealOneDamageToAllCreatures dealOneDamageToAllCreatures;
OneCharacterCardDiscardToHand oneCharacterCardDiscardToHand;
DestroyOneTargetCreature destroyOneTargetCreature;
OneTargetCreatureGainsTrample oneTargetCreatureGainsTrample;
AllWhiteCreaturesGainP1P1 allWhiteCreaturesGainP1P1;
AllBlackCreaturesGainM1M1 allBlackCreaturesGainM1M1;
AllBlackCreaturesGainP2P0 allBlackCreaturesGainP2P0;
AllGreenCreaturesLoseTrample allGreenCreaturesLoseTrample ;
OneTargetCreatureLosesFirstStrike oneTargetCreatureLosesFirstStrike ;

//Sorcery cards
sorceryCard Disenchant("Disenchant","1W","White",destroyOneTargetEnchantment);
sorceryCard Lightning_Bolt("Lightning Bolt","1G","Green",dealTwoDamageCreatureOrPlayer);
sorceryCard Flood("Flood","1GW","Green",destroyOneTargetLand);
sorceryCard Reanimate("Reanimate","B","Black",oneCharacterCardDiscardToHand);
sorceryCard Plague("Plague","2B","Black",dealOneDamageToAllCreatures);
sorceryCard Terror("Terror","1B","Black",destroyOneTargetCreature);

//Enchantment cards
enchantmentCard Rage("Rage","G","Green",oneTargetCreatureGainsTrample);
enchantmentCard Holy_War("Holy War","1W","White",allWhiteCreaturesGainP1P1);
enchantmentCard Holy_Light("Holy Light","1W","White",allBlackCreaturesGainM1M1);
enchantmentCard Unholy_War("Unholy War","1B","Black",allBlackCreaturesGainP2P0);
enchantmentCard Restrain("Restrain","2R","Red",allGreenCreaturesLoseTrample);
enchantmentCard Slow("Slow","B","Black",oneTargetCreatureLosesFirstStrike);


//for(it = player1Deck.begin(); it<player1Deck.end(); it++) {
//
//}

unique_ptr<Player>player1 = make_unique<Player>("player1");
unique_ptr<Player>player2 = make_unique<Player>("player2");



//Players deck optimization

for(int i = 0; i < 1; i++) {
    for(int p = 0; p < 5; p++) {
        player1->AddLandCards(Plains);
        player2->AddLandCards(Swamp);
    }
    for(int j = 0; j< 3; j++) {
        player1->AddLandCards(Forest);
        player2->AddLandCards(Mountain);
    }
    player1->AddLandCards(Island);
    player2->AddLandCards(Island);

    player1->AddCreatureCards(Soldier);
    player1->AddCreatureCards(Soldier);
    player1->AddCreatureCards(Soldier);
    player1->AddCreatureCards(Armored_Pegasus);
    player1->AddCreatureCards(Armored_Pegasus);
    player1->AddCreatureCards(White_Knight);
    player1->AddCreatureCards(Angry_Bear);
    player1->AddCreatureCards(Guard);
    player1->AddCreatureCards(Werewolf);

    player1->AddSorceryCards(Reanimate);
    player1->AddSorceryCards(Plague);
    player1->AddSorceryCards(Terror);
    player1->AddSorceryCards(Terror);

    player1->AddEnchantmentCards(Rage);
    player1->AddEnchantmentCards(Holy_War);
    player1->AddEnchantmentCards(Holy_Light);

    player2->AddCreatureCards(Skeleton);
    player2->AddCreatureCards(Skeleton);
    player2->AddCreatureCards(Skeleton);
    player2->AddCreatureCards(Ghost);
    player2->AddCreatureCards(Ghost);
    player2->AddCreatureCards(Black_Knight);
    player2->AddCreatureCards(Orc_Maniac);
    player2->AddCreatureCards(Hobgoblin);
    player2->AddCreatureCards(Vampire);

    player2->AddSorceryCards(Reanimate);
    player2->AddSorceryCards(Plague);
    player2->AddSorceryCards(Terror);
    player2->AddSorceryCards(Terror);

    player2->AddEnchantmentCards(Unholy_War);
    player2->AddEnchantmentCards(Restrain);
    player2->AddEnchantmentCards(Slow);

}

player1->printDeck();
player2->printDeck();

int roundCount = 1;

while (true) {
    cout << "---------------------------IN PLAY---------------------------" << endl;
    player1->printInPlay();
    player2->printInPlay();

    cout << "---------------------------HAND---------------------------" << endl;
    player1->printInHandInfo();
    player2->printInHandInfo();

    cout << "---------------------------HP---------------------------" << endl;
    cout << "HP of " << player1->getName() << " " <<player1->getHP() << " " << endl;
    cout << "HP of " << player2->getName() << " " <<player2->getHP() << " " << endl;


    vector<landCard> :: iterator  i;
    for(i = player1->getHandLandCards().begin(); i < player1->getHandLandCards().end(); i++) {
        player1->AddMana(1,i->getManaType());
    }


    cout << "---------------------------COMBAT---------------------------" << endl;
    int ranNum = rand() % player1->getCreatureCards().size() + 1;

    player1->getCreatureCards().at(ranNum).setTapped(true);

    AttackToCard(player1->getCreatureCards().at(ranNum),player1,player2,player2->getCreatureCards().at(ranNum));


    AttackToPlayer(player1->getCreatureCards().at(ranNum),player2);

    cout << "---------------------------HP---------------------------" << endl;

    cout << "HP of " << player1->getName() << " " <<player1->getHP() << " " << endl;
    cout << "HP of " << player2->getName() << " " <<player2->getHP() << " " << endl;

    roundCount++;

    cout << "ROUND COUNT << " << roundCount << endl;

    cout << "---------------------------HP---------------------------" << endl;


    if(player1->getHP() <= 0) {
        cout << "Player: " << player2->getName() << " has won the game" << endl;
        break;
    } else if(player2->getHP() <= 0){
        cout << "Player: " << player1->getName() << " has won the game" << endl;
        break;
    }
    if(player1->getLibraryCount() == 0|| player2->getLibraryCount() == 0) {
        break;
    }



}
return 0;

};

//HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//COORD CursorPosition;
//
//void gotoxy(int x, int y){
//    CursorPosition.X=x;
//    CursorPosition.Y=y;
//    SetConsoleCursorPosition(console,CursorPosition);
//}
//
//int P1presetx;
//int P1presety;
//
//int PFplayerx;
//int PFplayery;
//
//
//int Enpresetx;
//int Enpresety;
//
//// Y COORDINATES
////0 1 2 3 4 5 6   enemy hand
////7 8 9 gap
////10 11 12 enemy field
//// 13 14 15 gap
//// 16 17 18 player field
//// 19 20 21 player hand
//// 22 23 24 25 26 27 28
//
//void genfieldlocation(){
//    gotoxy(PFplayerx, PFplayery); cout<< "|"<<" name     "<<"|"<< endl;
//    gotoxy(PFplayerx,PFplayery+1);cout<<"|" <<"atk: "<< "def: "<< "|" <<endl;
//    gotoxy(PFplayerx,PFplayery+2);cout<< "|"<< "Ability:  "<< "|"<< endl;
//
//}
//void genplayerhand(){
//    gotoxy(P1presetx, P1presety); cout<< "|"<<" name     "<<"|"<< endl;
//    gotoxy(P1presetx,P1presety+1);cout<<"|" <<"atk: "<< "def: "<< "|" <<endl;
//    gotoxy(P1presetx,P1presety+2);cout<< "|" <<"mana: "<<"    |"<<endl;
//    gotoxy(P1presetx,P1presety+3);cout<< "|" << "type:     "<< '|'<<endl;
//    gotoxy(P1presetx,P1presety+4);cout<< "|"<< "Ability:  "<< "|"<< endl;
//    gotoxy(P1presetx,P1presety+5);cout<< "|"<<"text      "<<"|"<<endl;
//    gotoxy(P1presetx,P1presety+6);cout<< "|"<<"text      "<<"|"<<endl;
//}
//void genenemyhand(){
//    gotoxy(Enpresetx, Enpresety); cout<< "|"<<" name     "<<"|"<< endl;
//    gotoxy(Enpresetx,Enpresety+1);cout<<"|" <<"atk: "<< "def: "<< "|" <<endl;
//    gotoxy(Enpresetx,Enpresety+2);cout<< "|" <<"mana: "<<"    |"<<endl;
//    gotoxy(Enpresetx,Enpresety+3);cout<< "|" << "type:     "<< '|'<<endl;
//    gotoxy(Enpresetx,Enpresety+4);cout<< "|"<< "Ability:  "<< "|"<< endl;
//    gotoxy(Enpresetx,Enpresety+5);cout<< "|"<<"text      "<<"|"<<endl;
//    gotoxy(Enpresetx,Enpresety+6);cout<< "|"<<"text      "<<"|"<<endl;
//}
//
//int cardsinhandenemy=5;
//int cardsinhandplayer=5;
//
//int cardsinenemyfield;
//int cardsinplayerfield;
//int turn;

//void turnfunction(){
// char in = getche();
//  turn=0;
// if (in==0) turn+1;

//  for(int cardinhand=5; cardinhand<7;cardinhand++){
//     cardinhand=cardinhand+turn;
//      cardsinhandplayer=cardinhand+turn;
//  cardsinhandenemy=cardinhand+turn;
//    system("cls");
//      break;
//  }
//}

//void generatetestenemyhand(){
//    for (int i=0; i<=cardsinhandenemy-1; i++){
//        Enpresetx=1;
//        Enpresety=0;
//        Enpresetx= Enpresetx+15*i;
//        genenemyhand();
//    }
//}
//void generatetestplayerhand(){
//    for (int i=0; i<=cardsinhandplayer-1; i++){
//        P1presetx=1;
//        P1presety=32;
//        P1presetx= P1presetx+15*i;
//        genplayerhand();
//    }
//}
//void enemyhandloation(){
//    Enpresety=0;
//    char ch = getch();
//    if (ch == 'q' || ch == 'Q' ) {
//        Enpresetx=1;
//    }
//    if (ch == 'w' || ch == 'W') {
//        Enpresetx=16;
//    }
//    if (ch == 'e' || ch == 'E') {
//        Enpresetx=31;
//    }
//    if (ch == 'r' || ch == 'R') {
//        Enpresetx=46;
//    }
//    if (ch == 't' || ch == 'T') {
//        Enpresetx=61;
//    }
//    if (ch == 'y'|| ch == 'Y') {
//        Enpresetx=76;
//    }
//    if (ch == 'u'|| ch == 'U' ) {
//        Enpresetx=91;
//    }
//    genenemyhand();
//}
//void playerhandlocation(){
//
//    P1presety=32;
//    char ch = getch();
//    if (ch == 'a' || ch == 'A') {
//        P1presetx=1;
//    }
//    if (ch == 's' || ch == 'S') {
//        P1presetx=16;
//    }
//    if (ch == 'd' || ch == 'D') {
//        P1presetx=31;
//    }
//    if (ch == 'f' || ch == 'F') {
//        P1presetx=46;
//    }
//    if (ch == 'g' || ch == 'G') {
//        P1presetx=61;
//    }
//    if (ch == 'h' || ch == 'H') {
//        P1presetx=76;
//    }
//    if (ch == 'j' || ch == 'J') {
//        P1presetx=91;
//    }
//    genplayerhand();
//}
//void instructions(){
//    system("cls");
//    cout<<"Instructions"<<endl;
//    cout<<"/-------------------"<<endl;
//    cout<<"/Not so Magic The Gathering is a card game in which players cast spells, summon creatures, and exploit magic objects to defeat their opponents."<<endl;
//    cout<<"/Select a card from your hand and play it if you have enough mana"<<endl;
//    cout<<"/Each player can have maximum of 7 cards in their hands if they draw a card while their hand is full that card goes directly to their discard pile"<<endl;
//    cout<<"/Most of the cards have unique abilities that can buff your own cards, deal damage to creatures or remove enchantments"<<endl;
//    cout<<"/Defeat your enemies cards first to attack them directly"<<endl;
//    cout<<"/Whoever gets down to zero health or runs out of cards loses"<< endl;
//    cout<<"/n Press 'escape' to exit"<<endl;
//    cout<<"/n Press any key to go back to menu";
//    getch();
//}
//void play() {
//    system("cls");
//    while (1) {
//        if (kbhit()) {
//            char ch = getch();
//            generatetestenemyhand();
//            generatetestplayerhand();
//            //turnfunction();
//
//            //enemyhandloation();
//            //playerhandlocation();
//
//        }
//    }
//}
//int main() {
//    do {
//        system("cls");
//        gotoxy(10,5); cout<< "----------------------------";
//        gotoxy(10,6); cout<< "|Not So Magic The Gathering|";
//        gotoxy(10,7); cout<< "----------------------------";
//        gotoxy(10,9); cout<< " 1. START GAME ";
//        gotoxy(10,10); cout<< " 2. INSTRUCTIONS ";
//        gotoxy(10,11); cout<< " 3. QUIT ";
//        gotoxy(10,13); cout<< " SELECT OPTION: ";
//        char op = getche();
//
//        if (op == '1') play();
//        else if (op=='2') instructions();
//        else if(op=='3') exit(0);
//    } while (1);
//}



