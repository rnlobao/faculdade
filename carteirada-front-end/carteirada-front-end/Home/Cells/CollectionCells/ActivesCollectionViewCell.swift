//
//  ActivesCollectionViewCell.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 20/09/22.
//

import UIKit

class ActivesCollectionViewCell: UICollectionViewCell {

    @IBOutlet weak var backgroundActives: UIView!
    @IBOutlet weak var imageActives: UIImageView!
    @IBOutlet weak var labelActives: UILabel!
    
    static let identifier = "ActivesCollectionViewCell"
    
    func setupActives(symbolImage: String, typeOfActives: String) {
        backgroundActives.backgroundColor = UIColor(named: "light-green-carteirada")
        backgroundActives.layer.cornerRadius = 10
        backgroundActives.layer.shadowColor = UIColor.black.cgColor
        backgroundActives.layer.shadowOffset = CGSize(width: 0.0, height: 1.0)
        backgroundActives.layer.shadowRadius = 1.0
        backgroundActives.layer.shadowOpacity = 0.5
        backgroundActives.layer.masksToBounds = false
        
        imageActives.image = UIImage(systemName: symbolImage)
        imageActives.contentMode = .scaleAspectFit
        
        labelActives.textColor = UIColor.black
        labelActives.font = UIFont(name: "Poppins-Medium", size: 15)
        labelActives.text = typeOfActives
    }
    
    static func nib() -> UINib {
        return UINib(nibName: "ActivesCollectionViewCell", bundle: nil)
    }

}
