#include "framework.h"
#include "SRV.h"

SRV::SRV(wstring path)
{
	ScratchImage image;
	LoadFromWICFile(path.c_str(), WIC_FLAGS_NONE, nullptr, image);

	CreateShaderResourceView(DEVICE.Get(), image.GetImages(),
		image.GetImageCount(), image.GetMetadata(), _srv.GetAddressOf());
}

SRV::~SRV()
{
}

void SRV::SetSRV(UINT slot)
{
	DEVICECONTEXT->PSSetShaderResources(slot, 1, _srv.GetAddressOf());
}
