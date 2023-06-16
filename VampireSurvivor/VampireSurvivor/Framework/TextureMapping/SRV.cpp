#include "framework.h"
#include "SRV.h"

SRV::SRV(wstring path)
{
    ScratchImage image;
    LoadFromWICFile(path.c_str(), WIC_FLAGS_NONE, nullptr, image);

    _imageSize.x = image.GetMetadata().width;
    _imageSize.y = image.GetMetadata().height;

    CreateShaderResourceView(DEVICE.Get(), image.GetImages(),
        image.GetImageCount(), image.GetMetadata(), _srv.GetAddressOf());
}

void SRV::SetSRV(UINT slot)
{
    DC->PSSetShaderResources(slot, 1, _srv.GetAddressOf());
}
