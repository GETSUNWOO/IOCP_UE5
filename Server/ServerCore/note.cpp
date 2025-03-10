
#pragma region 패킷 설계

// id 설계 썰
// 
//TemplateID : 데이터 시트에 있는 아이디 (1번 단검,, 2번 양손검 ,,,,) // 기획자 관리
//DbId : 데이터베이스 상에서 아이디 (몬스터는 dbid가 없다!)
//GameID : 처음에 서버를 띄웠을 때 구분하기 위한 아이디(10번 id 몬스터를 공격하겠다)

// uint64 gameid : 64비트로 어마어마하게 큰 범위 []보통 데이터를 좀 낑겨서 저장하는데 일케 안할거임

#pragma endregion

#pragma region protobuf 작업

// 일반적인 변수에서 get set 함수
pkt.set_success(true); // set
pkt.success(); // get


// repeated 변수에서

Protocol::PlayerInfo* P = new Protocol::PlayerInfo();
P->set_x(0);
P->set_y(0);
P->set_z(0);
P->copyFrom();

Protocol::S_ENTER_GAME pkt;

pkt.set_allocated_player(P);// set 
pkt.player(); // get
pkt.release_player();

// 기본적으로 pkt 에서 release_player 에서 밀어줌

//벡터 넣어주는 느낌
pkt.players(0);// get_players (1. 인덱스 받는 버젼, 다 받는 버젼)

Protocol::S_LOGIN pkt;
for (int32 i = 0; i < pkt.players_size(); i++)
{
	const Protocol::PlayerInfo* p = pkt.add_players();
	p->set_x(10);
}

for (auto& p : pkt.players()) // 이것도 된다
{

}


#pragma endregion


#pragma region spawn 1

// 패킷 설계 순서대로 하는 연습을 해보자

// 1. Login

// client에서 서버 커넥트 일때 c_login 을 만들어서 보낸다
// server에서 그걸 받는다

// 2. enter



#pragma endregion

#pragma region Player, MyPlayer

// 내가 컨트롤하는 플레이어와 남이 컨트롤하는 플레이어(NPC 같은 느낌) 어떻게 구분할 것인가?

// 서버쪽 패킷에서 ENTERGAME이랑 SPAWN으로 나눠놨으니까 패킷으로 구분할 순 있음
// 언리얼 엔진에서는 POSSESS 한걸로 구분할 수도 있음

// 핵심주제 : 내가 관리하는 플레이어인지 남이 관리하는 플레이어인지 구분하는 수단을 만드는 것

// 공용적인 기능은 묶어놔야함 (상속으로)

// 따라서 내가 플레이하는 플레이어는 myplayer로 player를 상속받아서 사용하자

#pragma endregion

#pragma region 이동

// 이동하는 방법은 크게 두가지로 나뉜다.

//1 . 클라에서 이동하고 서버에 보내서 그걸 브로드캐스팅
//2 . 클라에서 이동요청하고 서버에서 허락한 후 이동과 동시에 브로드캐스팅

// 이거에 대한 답은 게임에 따라 다름
// 예를 들어 마우스로 이동하는 게임(롤) -> 서버에서 허락을 한다음에 이동하는 2번 채택하는 경우가 많음
// 
// 키보드 기반은 -> 서버에서 허락을 받으면 좀 멀미나고 답답하기 때문에 1번 채택하는 경우가 많음 (테라, 와우 충돌X)
// -> 이동을 했는데 원래 못가는 곳이었다.. EX)충돌.. 서버쪽 허락을 구하는게 낫다(리니지)

// ** 우리는 명확하게 3인칭 게임을 진행중이기 때문에 1번 방식을 채택할 것이다


// 매프레임 이동패킷을 보낸다? 말도안된다
// 대략적으로 0.2초마다 한번씩 보내는게 일반적이다

// 여기까지 수행하면 뚝뚝 끊겨서 위치가 갱신된다

#pragma endregion

#pragma region 보정

// 뚝뚝 끊기는 걸 어떻게 처리할까.. 0.2초 딜레이를 줄인다? 말이 안됨 서버 부하가 견디지 못함

// 따라서 이동값 사이에 보정을 해줘야 한다
// DESTINFO 목적지와 보정 (근사값으로 보정)
// -> 이슈는 이동움직임 틀어질 수 있다..오차발생 가능성 o

// 결국 상태를 받아줄 필요가 있다ㅣ (갑자기 확 꺾을때는 패킷을 한 번 더 보낸다든가 정지상태라든가)

// **언리얼 엔진 이슈

// 만든 폰 자체가 컨트롤러가 딱히 없는 상황에서 addmoveinput 변경을 하면 run physics With no controller 를 켜줘야함


//todo !! 
// 1. 서버렉이 걸려서 이동값에 한참 못미치는 보정처리를 하고  있는 경우 순간이동이나 5배속같은 처리를 해주어야함
// 2. 방향을 순간적으로 틀었을때 바로 패킷을 보내주어야 한다

// 3. 충돌의 경우 지금 많이 어긋날 것이다.(나의 생각으로는 충돌 상태를 따로 관리해서 움직임을 블락하는 것을 전체에 브로드캐스팅 하면 될 것 같다..)

#pragma endregion

#pragma region job

// 서버 프로그래머 면접에 가장 많이 나왔다

// 지금의 구조에서는 서로 패킷을 핑퐁하면서 주고받기에 일방적으로 서버에서 패킷을 줘야하는 npc나 몬스터가 애매하다..!


// 1. gameserver.cpp 에서 while문에 groom->update() 같은걸 만들어서 계속 보내주는 상황을 고려할 수 있을 것이다.

// 이제 멀티쓰레드 관련 이슈가 많이 문제가 될 것이다.. (게임로직 쓰레드,, 패킷주고받는 쓰레드,, update하는 쓰레드,,)

// 답은 커멘드 패턴이다!

// 패킷을 핸들링 하는 함수에서 functor를 만들어서 잡큐에 넣어주고 순차처리

// 따라서 패킷 핸들러 부분에서 doAsnyc 로 전부 바꿔서 jobqueue 비동기 버젼으로 처리함

// -> 이 것들을 어디서 소모해줄까?
// 1. 게임서버cpp에서 처리 (메인) -> 업무분담이 너무 안됌 / 쓰레드의 역할을 처음부터 고정하면 발생하는 고질적 문제
// 2. 잡큐에 푸시하는 순간 첫번째 job을 밀어넣은 쓰레드 녀석한테 실행까지 맡겨버린다

// 게임에서 구역이라는 개념.
//

// 
// actor단위의 방식 : 모든 액터에게 다 jobqueue를 달아준다. (각각의 스레드별로 담당한다) (가상의 룸 개념을 사용한다)
// TLS에 HEAP데이터를 고속복사해서 전역 데이터로 사용한다
// ---> 콘텐츠 개발 난이도가 극악
// <ROOM> 개념이었다면 Attack 코드를 만들어서 a 유저 찾고 b유저 찾고 a 공격력 b 체력 뺴고 이러면 되는데
// actor단위의 방식은 ... -> 서버에서 jobqueue에 공격을 예약하고 이래야함


// 결국 돌고돌아 어떻게 해결해야 할까.. 답은 없지만
// 결과적으로 최대한 하나의 쓰레드가 큰 영역을 담당하게 하되,
// astar, 몬스터 ai 등을 따로 빼주고


#pragma endregion

#pragma region 계층구조정리

// 꿀팁 : 패킷을 설계할때 많은 정보를 가정해놓고 그것을 채우지 않았을 경우에도 정상적으로 보내지고 심지어 null체크를 통한
// 패킷 판별을 이용해 빠르고 쉽게 작업을 할 수 있다.


#pragma endregion