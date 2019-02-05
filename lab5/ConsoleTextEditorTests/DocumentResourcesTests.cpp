#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleTextEditorLib/DocumentResources.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;
using namespace filesystem;
using namespace resources;

namespace ConsoleTextEditorTests
{		
	TEST_CLASS(DocumentResourcesTests)
	{
	public:
		CDocumentResources resources;

		TEST_METHOD(TempFolderExistsOnResourceCreationAndAbsendAfterResourceDestroying)
		{
			Path tmpfolderPath;
			{
				CDocumentResources resources;
				tmpfolderPath = resources.GetDirectoryPath();
				Assert::IsTrue(exists(tmpfolderPath));
			}
			Assert::IsTrue(!exists(tmpfolderPath));
		}

		TEST_METHOD(ResourceFileCopyHasBeenDeletedAfterResourceDeleting)
		{
			auto resource = resources.AddResource("../../ConsoleTextEditorTests/res/lamp.jpg", "image");
			auto filePath = resource->GetFilePath();
			Assert::IsTrue(exists(filePath));
			resource.reset();
			Assert::IsTrue(!exists(filePath));
		}

	};
}