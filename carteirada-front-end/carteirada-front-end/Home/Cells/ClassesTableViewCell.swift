//
//  ClassesTableViewCell.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 20/09/22.
//

import UIKit
import FirebaseDatabase
import FirebaseAuth

protocol goToDetailScreen {
    func goToAcaoScreen()
    func goToFiiScreen()
    func goToCriptoScreen()
}

class ClassesTableViewCell: UITableViewCell {

    @IBOutlet weak var collectionView: UICollectionView!
    var myActives: [String] = []
    var delegate: goToDetailScreen!

    
    func setup() {
        setupWhichAssetsUserHas()
        collectionView.delegate = self
        collectionView.dataSource = self
        collectionView.register(ActivesCollectionViewCell.nib(), forCellWithReuseIdentifier: ActivesCollectionViewCell.identifier)
    }
    
    private func setupWhichAssetsUserHas() {
        discoverActives(kindOf: "acoes")
        discoverActives(kindOf: "fii")
        discoverActives(kindOf: "cripto")
    }
    
    func discoverActives(kindOf: String) {
        let ref = Database.database().reference()
        let uid = Auth.auth().currentUser?.uid
        var totalMoney: Double = 0.0
        
        ref.child("users").child(uid!).child("assets").child(kindOf).child("inTotal").observe(.value) { data in
            totalMoney = data.value as! Double
            if totalMoney > 0.0 {
                self.myActives.append(kindOf)
                self.collectionView.reloadData()
            }
        }
    }
    
    func removeFromArr(whichKind: String) {
        if let index = myActives.firstIndex(of: whichKind) {
            myActives.remove(at: index)
        }
    }
}

extension ClassesTableViewCell: UICollectionViewDelegate, UICollectionViewDataSource {
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return 3
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "ActivesCollectionViewCell", for: indexPath) as! ActivesCollectionViewCell
        if indexPath.row == 0 {
            cell.setupActives(symbolImage: "chart.bar.fill", typeOfActives: "Ações")
        } else if indexPath.row == 1 {
            cell.setupActives(symbolImage: "dollarsign.square.fill", typeOfActives: "Criptoativos")
        } else if indexPath.row == 2 {
            cell.setupActives(symbolImage: "building.2", typeOfActives: "Fii's")
        }
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        if indexPath.row == 0 {
            delegate.goToAcaoScreen()
        }
        if indexPath.row == 1 {
            delegate.goToCriptoScreen()
        }
        if indexPath.row == 2 {
            delegate.goToFiiScreen()
        }
    }
}
