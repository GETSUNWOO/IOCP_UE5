#include "pch.h"
#include "ObjectUtils.h"
#include "GameSession.h"
#include "Player.h"

atomic<int64> ObjectUtils::s_idGenerator = 1;

PlayerRef ObjectUtils::CreatePlayer(GameSessionRef session)
{
	// ID »ý¼º±â
	const int64 newId = s_idGenerator.fetch_add(1);

	PlayerRef player = make_shared<Player>();
	player->playerInfo->set_objectid(newId);

	player->session = session;
	session->player.store(player);

	return player;
}
