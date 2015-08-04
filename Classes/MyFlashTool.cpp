#include "MyFlashTool.h"
#include <json/document.h>

Animate * MyFlashTool::readJsonSpriteSheet(std::string jsonFile, float delayPerUnit){


	rapidjson::Document doc;
	std::string fileContent = FileUtils::getInstance()->getStringFromFile(jsonFile);
	fileContent.erase(0, fileContent.find_first_of('{'));
	doc.Parse<0>(fileContent.c_str());
	std::string imgFileName = doc["meta"]["image"].GetString();
	auto &frames = doc["frames"];
	auto sfc = SpriteFrameCache::getInstance();
	Vector<AnimationFrame*> animFrames;
	for (auto m = frames.MemberonBegin(); m != frames.MemberonEnd(); m++) {
		auto frameName = m->name.GetString();
		auto & frameProperties = m->value["frame"];
		auto & spriteSourceSize = m->value["spriteSourceSize"];
		auto sf = sfc->getSpriteFrameByName(frameName);
		if (!sf) {
			sf = SpriteFrame::create(imgFileName, Rect(frameProperties["x"].GetInt(), frameProperties["y"].GetInt(), frameProperties["w"].GetInt(), frameProperties["h"].GetInt()), m->value["rotated"].GetBool(), Vec2(spriteSourceSize["x"].GetInt(), spriteSourceSize["y"].GetInt()), Size(spriteSourceSize["w"].GetInt(), spriteSourceSize["h"].GetInt()));
			sfc->addSpriteFrame(sf, frameName);
		}
		ValueMap vm;
		animFrames.pushBack(AnimationFrame::create(sf, delayPerUnit, vm));
		//animFrames.pushBack(AnimationFrame::create(sf, delayPerUnit, ValueMapNull));
	}
	return nullptr;
}

Animate * MyFlashTool::readPlistAnimate(std::string fileName, float delayPerUnit){
	Vector<SpriteFrame*> arr;
	for (int i = 1; i <= 6;i++)
	{
		std::string str = StringUtils::format("%s_Walk_0%d.png", fileName.c_str(), i);
		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
		arr.pushBack(frame);
	}

	auto animation = Animation::createWithSpriteFrames(arr, delayPerUnit);
	return Animate::create(animation);
}